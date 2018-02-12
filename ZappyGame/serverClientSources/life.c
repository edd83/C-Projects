/*
** life.c for life in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Jul  8 16:07:57 2014 lardet
** Last update Sun Jul 20 17:49:06 2014 lardet
*/

#include "server.h"

void		fill_life(t_player *player, t_server *serv)
{
  float		temp;

  temp = (float)(player->inventory[0] * 126) / (float)serv->delay;
  player->life.tv_sec = (int)temp;
  player->life.tv_usec = ((temp - (int)temp) * pow(10, 6));
}

void		update_life(t_server *serv)
{
  float		temp;
  t_player	*player;
  t_team	*team;

  team = serv->begin_team;
  while (team != NULL)
    {
      temp = 0;
      player = team->begin;
      while (player != NULL)
	{
	  temp = (float)(player->inventory[0] * 126) / (float)serv->delay;
	  player->life.tv_sec = (int)temp;
	  player->life.tv_usec = ((temp - (int)temp) * pow(10, 6));
	  player = player->next;
	}
      team = team->next;
    }
}

int		player_die(t_player *player, t_server *serv)
{
  int		len;
  char		buff[10];
  int		save_id;

  save_id = player->id;
  if (send(player->fd, "mort\n", 5, 0) == -1)
    return (-1);
  erase_fd(serv, player->fd);
  len = sprintf(buff, "%s %i\n", "pdi", save_id);
  if (send(serv->fd_graphic, buff, len, 0) == -1)
    return (-1);
  return (0);
}

void		update_life_with_add(t_player *player, t_server *serv)
{
  float		temp;

  temp = (float)126 / (float)serv->delay;
  player->life.tv_sec += (int)temp;
  if (player->life.tv_usec + ((temp - (int)temp) * pow(10, 6)) >= 1000000)
    {
      player->life.tv_sec += 1;
      player->life.tv_usec = ((player->life.tv_usec
			       + ((temp - (int)temp) * pow(10, 6))) - 1000000);
    }
  else
    player->life.tv_usec += ((temp - (int)temp) * pow(10, 6));
}

void		update_life_with_put(t_player *player, t_server *serv)
{
  float		temp;

  temp = (float)126 / (float)serv->delay;
  if (player->life.tv_sec - (int)temp <= 0)
    player_die(player, serv);
  else
    player->life.tv_sec -= (int)temp;
  if (player->life.tv_usec - ((temp - (int)temp) * pow(10, 6)) <= 0)
    {
      if (player->life.tv_sec - 1 <= 0)
	player_die(player, serv);
      else
	player->life.tv_sec -= 1;
      if (player->life.tv_usec - ((temp - (int)temp) * pow(10, 6)) == 0)
	player->life.tv_usec = 0;
      else
	player->life.tv_usec = (1000000
				+ (player->life.tv_usec
				   + ((temp - (int)temp) * pow(10, 6))));
    }
  else
    player->life.tv_usec -= ((temp - (int)temp) * pow(10, 6));
}
