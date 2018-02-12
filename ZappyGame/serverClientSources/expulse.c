/*
** expulse.c for expulse in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Jul  2 17:38:29 2014 lardet
** Last update Sun Jul 20 17:34:31 2014 Fabien Casoni
*/

#include "server.h"

int				expluse(char *buff, int fd, t_server *serv)
{
  t_team			*team;
  t_player			*player;
  t_player			*play;
  int				find;

  (void)buff;
  find = 0;
  if ((play = search_player_by_fd(fd, serv)) == NULL)
    return (-1);
  team = serv->begin_team;
  while (team != NULL)
    {
      player = team->begin;
      loop_player_orient(player, play, &find, serv);
      team = team->next;
    }
  fill_expulse(play, serv, find);
  return (0);
}

void				fill_expulse(t_player *play, t_server *serv, int find)
{
  if (find == 1)
    {
      play->act[0].ress = 0;
      fill_timeout(play, 7, serv, 8);
    }
  else
    {
      play->act[0].ress = -1;
      fill_timeout(play, 7, serv, 8);
    }
}

void				loop_player_orient(t_player *player,
						   t_player *pla, int *find,
						   t_server *serv)
{
  char				buff[4096];

  while (player != NULL)
    {
      if (player->x == pla->x && player->y == pla->y && player->id != pla->id)
	{
	  sprintf(buff, "%s %i\n", "pex", player->id);
	  if (send(serv->fd_graphic, buff, strlen(buff), 0) == -1)
	    return ;
	  sprintf(buff, "%s %i %i %i %i\n", "ppo", player->id, player->x,
		  player->y, player->orient);
	  if (send(serv->fd_graphic, buff, strlen(buff), 0) == -1)
	    return ;
	  if (message_expulse(buff, player, serv, pla) == -1)
	    return ;
	  *find = 1;
	}
      player = player->next;
    }
}

int				push_player(t_player *player, t_player *play)
{
  int				orient;

  if (play->orient == 1)
    {
      player->y -= 1;
      orient = 3;
    }
  else if (play->orient == 2)
    {
      player->x += 1;
      orient = 4;
    }
  else if (play->orient == 3)
    {
      player->y += 1;
      orient = 1;
    }
  else
    {
      player->x -= 1;
      orient = 2;
    }
  return (orient);
}

int				broadcast(char *buff, int fd, t_server *serv)
{
  t_player			*player;

  if ((player = search_player_by_fd(fd, serv)) == NULL
      || (strlen(buff) < 12) || (strlen(buff) > 412))
    return (-1);
  sprintf(player->act[0].msg, "%s", (buff + 10));
  fill_timeout(player, 7, serv, 9);
  return (0);
}
