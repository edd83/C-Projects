/*
** content_func.c for zappy in /home/casoni_f/clone/PSU_2013_zappy/serverClientSources
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Mon Jun 30 11:26:08 2014 Fabien Casoni
** Last update Sat Jul 19 16:30:33 2014 Fabien Casoni
*/

#include "server.h"

int		count_arg(char **arg)
{
  int		i;

  i = -1;
  while (arg[++i] != NULL);
  return (i);
}

int		check_ress(int x, int y, char *buff, t_server *serv)
{
  int		i;
  t_ressources	*ress;
  char		b[4096];
  int		count[7];

  memset(b, 0, 412);
  i = -1;
  while (++i < 7)
    count[i] = 0;
  ress = serv->ress;
  while (ress != NULL)
    {
      if ((int)ress->x == x && (int)ress->y == y
	  && ress->flag == 1)
	count[ress->type_ress] += 1;
      ress = ress->next;
    }
  sprintf(b, "%s%d %d %d %d %d %d %d\n", buff, count[0], count[1], count[2],
	  count[3], count[4], count[5], count[6]);
  return (sprintf(buff, "%s", b));
}

void		check_player(int x, int y, char *buff, t_server *serv)
{
  t_team	*team;
  t_player	*p;

  team = serv->begin_team;
  while (team != NULL)
    {
      p = team->begin;
      while (p != NULL)
	{
	  printf("%d\n", p->id);
	  if ((int)p->x == x && (int)p->y == y)
	    strcat(buff, "player,");
	  p = p->next;
	}
      team = team->next;
    }
}

int		content_case2(int x, int y, int t, t_server *serv)
{
  char		buf[4096];
  int		len;

  memset(buf, 0, 4096);
  sprintf(buf, "bct %d %d ", x, y);
  len = check_ress(x, y, buf, serv);
  if (send(t, buf, len, 0) == -1)
    return (-1);
  return (0);
}
