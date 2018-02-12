/*
** func_player.c for func_player in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Jun 27 11:45:11 2014 lardet
** Last update Sat Jul 19 17:06:32 2014 lardet
*/

#include "server.h"

t_player	*add_head_player(t_team *team, t_server *serv, int fd)
{
  if ((team->player = malloc(sizeof(*serv->team->player))) == NULL)
    return (NULL);
  memset(team->player, 0, sizeof(*team->player));
  team->player->id = serv->i;
  serv->i = serv->i + 1;
  team->player->level = 1;
  team->player->orient = 1;
  team->player->fd = fd;
  add_fd(team, fd);
  team->player->inventory[0] = 10;
  team->player->x = ((serv->i * 22) % serv->map->x);
  team->player->y = ((serv->i * 124) % serv->map->y);
  team->player->next = NULL;
  team->begin = team->player;
  return (team->begin);
}

t_player	*add_end_player(t_team *team, t_server *serv, int fd)
{
  t_player	*player;
  t_player	*player2;

  player = team->begin;
  while (player->next != NULL)
    player = player->next;
  if ((player2 = malloc(sizeof(*serv->team->player))) == NULL)
    return (NULL);
  memset(player2, 0, sizeof(*player2));
  player2->id = serv->i;
  serv->i = serv->i + 1;
  player2->level = 1;
  player2->orient = 1;
  player2->fd = fd;
  add_fd(team, fd);
  player2->inventory[0] = 10;
  player2->x = ((serv->i * 57) % serv->map->x);
  player2->y = ((serv->i * 199) % serv->map->y);
  player2->next = NULL;
  player->next = player2;
  return (player2);
}

int		add_player(t_team *team, int *find, t_server *serv, int fd)
{
  t_player	*player;

  if (team->player == NULL)
    {
      player = add_head_player(team, serv, fd);
      fill_life(player, serv);
      *find = 1;
      team->nb_client_permitted -= 1;
    }
  else
    {
      player = add_end_player(team, serv, fd);
      fill_life(player, serv);
      *find = 1;
      team->nb_client_permitted -= 1;
    }
  if (player == NULL)
    return (-1);
  if (*find == 1)
    if (message_player(fd, player, serv, team) == -1)
      return (-1);
  return (1);
}

int		player_already_exist(int fd, t_server *serv)
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
	    return (1);
	  player = player->next;
	}
      team = team->next;
    }
  return (0);
}

int		func_player(char *buff, int fd, t_server *serv)
{
  t_team	*team;
  int		find;

  find = 0;
  team = serv->begin_team;
  while (team != NULL && find != 1)
    {
      if (team_exist(buff, serv) == 0)
	{
	  if (team_is_ok(buff, team) == 0)
	    {
	      if (player_already_exist(fd, serv) == 0)
		{
		  if (add_player(team, &find, serv, fd) == -1)
		    return (-1);
		}
	      else
		return (-1);
	    }
	}
      team = team->next;
    }
  if (find == 0)
    return (-1);
  return (0);
}
