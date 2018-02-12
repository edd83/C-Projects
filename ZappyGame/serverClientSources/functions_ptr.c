/*
** functions_ptr.c for functions_ptr in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Jun 24 10:41:32 2014 lardet
** Last update Fri Jul 18 13:43:31 2014 Fabien Casoni
*/

#include "server.h"

int		level_player(char *buff, int t, t_server *serv)
{
  int		id;
  t_team	*team;
  t_player	*player;
  char		str[2];

  team = serv->team;
  if ((id = findNumber(buff)) == -1)
    return (-2);
  while (team != NULL)
    {
      player = team->begin;
      while (player != NULL)
	{
	  if (player->id == (unsigned int)id)
	    {
	      sprintf(str, "plv %d %d\n", player->id, player->level);
	      if (send(t, str, strlen(str), 0) == -1)
		return (-1);
	    }
	  player = player->next;
	}
      team = team->next;
    }
  return (0);
}

int		inventory_player(char *buff, int t, t_server *serv)
{
  int		id;
  t_team	*team;
  t_player	*player;
  char		*str;

  team = serv->team;
  if ((id = findNumber(buff)) == -1)
    return (-2);
  while (team != NULL)
    {
      player = team->begin;
      while (player != NULL)
	{
	  if (player->id == (unsigned int)id)
	    {
	      str = fill_str(player);
	      if (send(t, str, strlen(str), 0) == -1)
		return (-2);
	    }
	  player = player->next;
	}
      team = team->next;
    }
  return (0);
}

int		ask_time_unit(char *buff, int t, t_server *serv)
{
  int		len;

  if (strlen(buff) != 4)
    return (-1);
  len = sprintf(buff, "%s %i\n", "sgt", serv->delay);
  if (send(t, buff, len, 0) == -1)
    return (-1);
  return (0);
}

int		update_time_unit(char *buff, int t, t_server *serv)
{
  int		delay;
  int		len;

  if ((delay = findNumber(buff)) == -1)
    return (-2);
  serv->delay = delay;
  len = sprintf(buff, "%s %i\n", "sgt", serv->delay);
  if (send(t, buff, len, 0) == -1)
    return (-1);
  update_life(serv);
  return (0);
}

int		findNumber(char *buff)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (buff[i])
    {
      if (buff[i] == '-')
	return (-1);
      if (buff[i] >= '0' && buff[i] <= '9')
        j = (j * 10) + (buff[i] - 48);
      i++;
    }
  return (j);
}
