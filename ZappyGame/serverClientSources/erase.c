/*
** erase.c for zappy in /home/casoni_f/Projets/PSU_2013_zappy/serverClientSources
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Sat Jul 12 18:55:00 2014 Fabien Casoni
** Last update Sat Jul 12 18:55:54 2014 Fabien Casoni
*/

#include	"server.h"

void		erase_fd(t_server *serv, int fd)
{
  int		i;
  int		find;
  t_player	*player;

  find = 0;
  i = 0;
  while (serv->t[i])
    {
      if (serv->t[i] == fd)
	{
	  find = 1;
	  if ((player = search_player_by_fd(fd, serv)) != NULL)
	    free_player(player, serv);
	  close(serv->t[i]);
	}
      if (find == 1)
	{
	  if (serv->t[i + 1])
	    serv->t[i] = serv->t[i + 1];
	  else
	    serv->t[i] = 0;
	}
      i++;
    }
  serv->nb_client -= 1;
}
