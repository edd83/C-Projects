/*
** movement.c for movement in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Jun 30 12:36:39 2014 lardet
** Last update Mon Jul  7 22:50:47 2014 lardet
*/

#include "server.h"

int		right(char *buff, int fd, t_server *serv)
{
  t_player	*player;

  (void)buff;
  if ((player = search_player_by_fd(fd, serv)) == NULL)
    return (-1);
  fill_timeout(player, 7, serv, 3);
  return (0);
}

void		change_orientation_left(t_player *player)
{
  if (player->orient == 1)
    player->orient = 4;
  else if (player->orient == 2)
    player->orient = 1;
  else if (player->orient == 3)
    player->orient = 2;
  else
    player->orient = 3;
}

void		change_orientation_right(t_player *player)
{
  if (player->orient == 1)
    player->orient = 2;
  else if (player->orient == 2)
    player->orient = 3;
  else if (player->orient == 3)
    player->orient = 4;
  else
    player->orient = 1;
}

int		advance(char *buff, int fd, t_server *serv)
{
  t_player	*player;

  (void)buff;
  if ((player = search_player_by_fd(fd, serv)) == NULL)
    return (-1);
  fill_timeout(player, 7, serv, 1);
  return (0);
}

int		left(char *buff, int fd, t_server *serv)
{
  t_player	*player;

  (void)buff;
  if ((player = search_player_by_fd(fd, serv)) == NULL)
    return (-1);
  fill_timeout(player, 7, serv, 2);
  return (0);
}
