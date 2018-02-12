/*
** manip.c for manip in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Jun 30 12:42:36 2014 lardet
** Last update Sat Jul 12 14:27:30 2014 lardet
*/

#include "server.h"

int		search_by_fd(int fd, t_server *serv)
{
  t_player	*player;
  t_team	*team;

  team = serv->begin_team;
  while (team != NULL)
    {
      player = team->begin;
      while (player != NULL)
	{
	  if (fd == player->fd)
	    return (player->id);
	  player = player->next;
	}
      team = team->next;
    }
  return (-2);
}

t_player	*search_by_id(int id, t_server *serv)
{
  t_player	*player;
  t_team	*team;

  team = serv->begin_team;
  while (team != NULL)
    {
      player = team->begin;
      while (player != NULL)
	{
	  if ((unsigned int)id == player->id)
	    return (player);
	  player = player->next;
	}
      team = team->next;
    }
  return (NULL);
}

void		advance_with_orientation(t_server *serv, t_player *player)
{
  if (player->orient == 1)
    if ((int)player->y - 1 < 0)
      player->y = serv->map->y - 1;
    else
      player->y = player->y - 1;
  else if (player->orient == 2)
    if (player->x + 1 >= serv->map->x)
      player->x = 0;
    else
      player->x = player->x + 1;
  else if (player->orient == 3)
    if (player->y + 1 >= serv->map->y)
      player->y = 0;
    else
      player->y = player->y + 1;
  else
    if ((int)player->x - 1 < 0)
      player->x = serv->map->x - 1;
    else
      player->x = player->x - 1;
}

t_player			*search_player_by_fd(int fd, t_server *serv)
{
  int				id_player;
  t_player			*play;

  id_player = search_by_fd(fd, serv);
  if (id_player == -1)
    return (NULL);
  if ((play = search_by_id(id_player, serv)) == NULL)
    return (NULL);
  return (play);
}
