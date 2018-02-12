/*
** erase_player.c for erase_player in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Jul 10 23:06:09 2014 lardet
** Last update Sun Jul 13 19:28:53 2014 Fabien Casoni
*/

#include "server.h"

int		loop_erase_player(t_player *player, t_player *play)
{
  while (play)
    {
      if (player == play->next)
	{
	  if (play->next->next)
	    play->next = play->next->next;
	  else
	    play->next = NULL;
	  return (1);
	}
      play = play->next;
    }
  return (0);
}

void		erase_player(t_player *player, t_team *team, int *find)
{
  t_player	*play;

  if (team->begin)
    {
      play = team->begin;
      if (player == team->begin && play->next)
	{
	  team->begin = play->next;
	  team->nb_client_permitted += 1;
	  *find = 1;
	}
      else if (player == team->begin)
	{
	  *find = 1;
	  team->begin = NULL;
	  team->player = NULL;
	  team->nb_client_permitted += 1;
	}
      else
	{
	  *find = loop_erase_player(player, play);
	  team->nb_client_permitted += 1;
	}
    }
}

void		free_player(t_player *player, t_server *serv)
{
  t_team	*team;
  int		i;
  int		find;

  i = -1;
  find = 0;
  while (player->act[++i].timer)
    reorder_array_player(player, serv);
  team = serv->begin_team;
  while (team != NULL && find != 1)
    {
      erase_player(player, team, &find);
      team = team->next;
    }
  free(player);
  if (serv->i != 0)
    serv->i = serv->i - 1;
}
