/*
** functions2_ptr.c for functions2_ptr in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Jun 24 10:44:22 2014 lardet
** Last update Sat Jul 19 17:57:40 2014 volpe
*/

#include "server.h"

int		size_map(char *buff, int t, t_server *serv)
{
  int		len;

  if (strlen(buff) != 4)
    return (-1);
  len = sprintf(buff, "%s %i %i\n", "msz", serv->map->x, serv->map->y);
  if (send(t, buff, len, 0) == -1)
    return (-1);
  return (0);
}

int		content_case(char *buff, int t, t_server *serv)
{
  char		**arg;
  char		buf[4092];
  int		x;
  int		y;
  int		len;

  memset(buf, 0, 4092);
  arg = strtowordtab(buff);
  if (strlen(buff) < 6 || count_arg(arg) < 3)
    return (-2);
  x = atoi(arg[1]);
  y = atoi(arg[2]);
  if (x < 0 || y < 0)
    return (-2);
  sprintf(buf, "bct %d %d ", x, y);
  len = check_ress(x, y, buf, serv);
  if (send(t, buf, len, 0) == -1)
    return (-1);
  return (0);
}

int		content_map(char *buff, int t, t_server *serv)
{
  int		x;
  int		y;

  x = -1;
  y = -1;
  if (buff == NULL || strlen(buff) != 4)
    return (-2);
  while (++y < (int)serv->map->y)
    {
      while (++x < (int)serv->map->x)
	content_case2(x, y, t, serv);
      x = -1;
    }
  return (0);
}

int		name_team(char *buff, int t, t_server *serv)
{
  t_team	*team;
  int		len;

  team = serv->begin_team;
  while (team != NULL)
    {
      len = sprintf(buff, "tna %s\n", team->name);
      if (send(t, buff, len, 0) == -1)
	return (-1);
      team = team->next;
    }
  return (0);
}

int		position_player(char *buff, int t, t_server *serv)
{
  int		id;
  t_team	*team;
  t_player	*player;
  char		str[2];

  team = serv->begin_team;
  if ((id = findNumber(buff)) == -1)
    return (-2);
  while (team != NULL)
    {
      player = team->begin;
      while (player != NULL)
	{
	  if (player->id == (unsigned int)id)
	    {
	      sprintf(str, "ppo %d %d %d %d\n", player->id, player->x,
		      player->y, player->orient);
	      if (send(t, str, strlen(str), 0) == -1)
		return (-1);
	    }
	  player = player->next;
	}
      team = team->next;
    }
  return (0);
}
