/*
** execute_actions_2.c for execute_actions_2 in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Jul  7 23:21:12 2014 lardet
** Last update Sun Jul 20 20:16:01 2014 Fabien Casoni
*/

#include "server.h"

int			take_exec(t_player *player, t_server *serv)
{
  if (player->act[0].ress != -1)
    message_inventory(player->fd, serv, player, player->act[0].ress);
  else
    if (send(player->fd, "ko\n", 3, 0) == -1)
      return (-1);
  return (0);
}

int			put_exec(t_player *player, t_server *serv)
{
  if (player->act[0].ress != -1)
    message_out_inventory(player->fd, serv, player, player->act[0].ress);
  else
    if (send(player->fd, "ko\n", 3, 0) == -1)
      return (-1);
  return (0);
}

int			expulse_exec(t_player *player, t_server *serv)
{
  char			b[4096];

  (void)serv;
  memset(b, 0, 4096);
  if (player->act[0].ress == 0)
    {
      if (send(player->fd, "ok\n", 3, 0) == -1)
	return (-1);
    }
  else
    if (send(player->fd, "ko\n", 3, 0) == -1)
      return (-1);
  return (0);
}

int			broadcast_exec(t_player *player, t_server *serv)
{
  char			buff[4096];
  int			len;

  memset(buff, 0, 4096);
  len = sprintf(buff, "pbc %d %s\n", player->id,
		player->act[0].msg);
  if (send(player->fd, "ok\n", 3, 0) == -1)
    return (-1);
  if (send(serv->fd_graphic, buff, len, 0) == -1)
    printf("No Graphic Client connected\n");
  send_message(serv, player);
  return (0);
}
