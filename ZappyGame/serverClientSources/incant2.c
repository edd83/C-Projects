/*
** incant2.c for incant2 in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Jul 19 10:33:16 2014 lardet
** Last update Sun Jul 20 16:44:08 2014 Fabien Casoni
*/

#include "server.h"

int				incantation(char *buff, int fd, t_server *serv)
{
  t_player			*player;
  char				buff2[4096];
  int				len;

  memset(buff, 0, 4096);
  memset(buff2, 0, 4096);
  if ((player = search_player_by_fd(fd, serv)) == NULL)
    return (-1);
  if (check_incant_player(serv, player, buff2)
      && check_incant_ress(serv, player))
    {
      len = sprintf(buff, "elevation en cours\n");
      send(serv->fd_graphic, buff2, strlen(buff2), 0);
      fill_timeout(player, 300, serv, 10);
    }
  else
    len = sprintf(buff, "ko\n");
  if (send(fd, buff, len, 0) == -1)
    return (-1);
  return (0);
}
