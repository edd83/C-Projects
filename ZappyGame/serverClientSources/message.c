/*
** message.c for message in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Jul  2 11:44:33 2014 lardet
** Last update Sun Jul 20 16:16:59 2014 lardet
*/

#include "server.h"

int		message_inventory(int fd, t_server *serv, t_player *player,
				  int id_ress)
{
  char		buff[4096];
  int		len;

  memset(buff, 0, 4096);
  if (send(fd, "ok\n", 3, 0) == -1)
    return (-1);
  len = sprintf(buff, "%s %i %i\n", "pgt", player->id, id_ress);
  if (send(serv->fd_graphic, buff, len, 0) == -1)
    return (-1);
  len = sprintf(buff, "%s %i %i %i %i %i %i %i %i %i %i\n", "pin", player->id,
	  player->x, player->y, player->inventory[0], player->inventory[1],
	  player->inventory[2], player->inventory[3], player->inventory[4],
	  player->inventory[5], player->inventory[6]);
  if (send(serv->fd_graphic, buff, len, 0) == -1)
    return (-1);
  content_case2(player->x, player->y, serv->fd_graphic, serv);
  return (0);
}

int		message_out_inventory(int fd, t_server *serv, t_player *player,
				      int i)
{
  char		buff[4096];
  int		len;

  memset(buff, 0, 4096);
  if (send(fd, "ok\n", 3, 0) == -1)
    return (-1);
  len = sprintf(buff, "%s %i %i\n", "pdr", player->id, i);
  if (send(serv->fd_graphic, buff, len, 0) == -1)
    return (-1);
  len = sprintf(buff, "%s %i %i %i %i %i %i %i %i %i %i\n", "pin", player->id,
	  player->x, player->y, player->inventory[0], player->inventory[1],
	  player->inventory[2], player->inventory[3], player->inventory[4],
	  player->inventory[5], player->inventory[6]);
  if (send(serv->fd_graphic, buff, len, 0) == -1)
    return (-1);
  content_case2(player->x, player->y, serv->fd_graphic, serv);
  return (0);
}

int		message_player(int fd, t_player *player, t_server *serv,
			       t_team *team)
{
  int		len;
  char		buff[4096];

  len = sprintf(buff, "%i\n", team->nb_client_permitted);
  if (send(fd, buff, len, 0) == -1)
    return (-1);
  len = sprintf(buff, "%i %i\n", serv->map->x, serv->map->y);
  if (send(fd, buff, len, 0) == -1)
    return (-1);
  len = sprintf(buff, "%s %d %d %d %d %d %s\n", "pnw", player->id, player->x,
		player->y, player->orient, player->level, team->name);
  if (send(serv->fd_graphic, buff, len,  0) == -1)
    return (-1);
  return (0);
}

int				message_expulse(char *buff, t_player *player,
						t_server *serv, t_player *pla)
{
  int				orient;

  orient = push_player(player, pla);
  sprintf(buff, "%s %i\n", "deplacement:", orient);
  if (send(player->fd, buff, strlen(buff), 0) == -1)
    return (-1);
  sprintf(buff, "%s %i %i %i %i\n", "ppo", player->id, player->x,
	  player->y, player->orient);
  if (send(serv->fd_graphic, buff, strlen(buff), 0) == -1)
    return (-1);
  return (0);
}
