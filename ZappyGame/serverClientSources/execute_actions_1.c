/*
** execute_actions_1.c for execute_actions_1 in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Jul  7 23:20:19 2014 lardet
** Last update Fri Jul 18 15:23:48 2014 Fabien Casoni
*/

#include "server.h"

int			avance_exec(t_player *player, t_server *serv)
{
  char			buff[4096];
  int			len;

  memset(buff, 0, 4096);
  if (send(player->fd, "ok\n", 3, 0) == -1)
    return (-1);
  advance_with_orientation(serv, player);
  len = sprintf(buff, "ppo %d %d %d %d\n", player->id,
		player->x, player->y, player->orient);
  if (send(serv->fd_graphic, buff, len, 0) == -1)
    return (-1);
  return (0);
}

int			left_exec(t_player *player, t_server *serv)
{
  char			buff[4096];
  int			len;

  memset(buff, 0, 4096);
  if (send(player->fd, "ok\n", 3, 0) == -1)
    return (-1);
  change_orientation_left(player);
  len = sprintf(buff, "ppo %d %d %d %d\n", player->id,
		player->x, player->y, player->orient);
  if (send(serv->fd_graphic, buff, len, 0) == -1)
    return (-1);
  return (0);
}

int			right_exec(t_player *player, t_server *serv)
{
  char			buff[4096];
  int			len;

  memset(buff, 0, 4096);
  if (send(player->fd, "ok\n", 3, 0) == -1)
    return (-1);
  change_orientation_right(player);
  len = sprintf(buff, "ppo %d %d %d %d\n", player->id,
		player->x, player->y, player->orient);
  if (send(serv->fd_graphic, buff, len, 0) == -1)
    return (-1);
  return (0);
}

int			see_exec(t_player *player, t_server *serv)
{
  int			len;
  char			buff[4096];
  int			coord[2];

  sprintf(buff, "{");
  coord[0] = player->x;
  coord[1] = player->y;
  check_ress_cli(player->x, player->y, buff, serv);
  check_player_cli(coord, player->id, buff, serv);
  sprintf(buff, "%s,", buff);
  if (player->orient == N || player->orient == S)
    if (player->orient == N)
      see_north(player, buff, serv);
    else
      see_south(player, buff, serv);
  else
    if (player->orient == O)
      see_west(player, buff, serv);
    else if (player->orient == E)
      see_east(player, buff, serv);
  len = sprintf(buff, "%s}\n", buff);
  if (send(player->fd, buff, len, 0) == -1)
    return (-1);
  return (0);
}

int			inventory_exec(t_player *player, t_server *serv)
{
  char			buff[4096];
  int			len;

  (void)serv;
  memset(buff, 0, 4096);
  len = sprintf(buff, "%s %i%s %i%s %i%s %i%s %i%s %i%s %i%s\n", "{nourriture",
	  player->inventory[0], ", linemate", player->inventory[1],
	  ", deraumère", player->inventory[2], ", sibur", player->inventory[3],
	  ", mendiane", player->inventory[4], ", phiras", player->inventory[5],
	  ", thystame", player->inventory[6], "}");
  if (send(player->fd, buff, len, 0) == -1)
    return (-1);
  return (0);
}
