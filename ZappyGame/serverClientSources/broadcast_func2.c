/*
** broadcast_func2.c for Zappy in /home/casoni_f/Projets/PSU_2013_zappy/serverClientSources
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Sun Jul 20 15:57:54 2014 Fabien Casoni
** Last update Sun Jul 20 20:05:32 2014 Fabien Casoni
*/

#include	"server.h"

int		north_east(int sendX, int sendY, int recvX, int recvY)
{
  float		res;

  if (sendY > recvY && sendX > recvX)
    {
      res = ((float)sendY - (float)recvY) / ((float)sendX - (float)recvX);
      if (res < 2 && res > 0.5)
	return (_TRUE_);
    }
  return (_FALSE_);
}

void		send_message(t_server *serv, t_player *player)
{
  int			len;
  char			buff[4096];
  t_team		*team;
  t_player		*p;
  int			coord[4];

  team = serv->begin_team;
  while (team != NULL)
    {
      p = team->begin;
      while (p != NULL)
	{
	  coord[0] = (int)player->x;
	  coord[1] = (int)player->y;
	  coord[2] = (int)p->x;
	  coord[3] = (int)p->y;
	  len = sprintf(buff, "message %d,%s\n",
			direction_broadcast(coord, p->orient),
			player->act[0].msg);
	  if (send(p->fd, buff, len, 0) == -1)
	    printf("Player %d not connected\n", p->id);
	  p = p->next;
	}
      team = team->next;
    }
}
