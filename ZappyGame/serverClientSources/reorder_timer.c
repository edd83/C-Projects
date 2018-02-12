/*
** reoder_timer.c for reorder_timer in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Jul  7 23:15:27 2014 lardet
** Last update Mon Jul  7 23:16:36 2014 lardet
*/

#include "server.h"

void			reorder_array_real(t_server *serv, t_player *player,
					   int *i)
{
  execute_command(player->act[0].id, player, serv);
  while (*i <= 8)
    {
      player->act[*i].id = player->act[*i + 1].id;
      player->act[*i].ress = player->act[*i + 1].ress;
      player->act[*i].timer = player->act[*i + 1].timer;
      player->act[*i].timer_micro = player->act[*i + 1].timer_micro;
      (*i) = (*i) + 1;
    }
  if (*i == 9)
    {
      player->act[*i].timer = 0;
      player->act[*i].timer_micro = 0;
    }
  player->i_tim--;
}

void			reorder_array(t_server *serv)
{
  int			i;
  t_player		*player;
  t_team		*team;

  team = serv->begin_team;
  while (team)
    {
      player = team->begin;
      while (player)
	{
	  i = 0;
	  if (player->i_tim > 0)
	    {
	      if (player->act[0].timer == 0 && player->act[0].timer_micro == 0)
		reorder_array_real(serv, player, &i);
	    }
	  player = player->next;
	}
      team = team->next;
    }
}

void			reorder_array_player(t_player *player, t_server *serv)
{
  int			i;

  i = 0;
  if (player->i_tim > 0)
    {
      if (player->act[0].timer == 0 && player->act[0].timer_micro == 0)
	{
	  execute_command(player->act[0].id, player, serv);
	  while (i <= 8)
	    {
	      player->act[i].id = player->act[i + 1].id;
	      player->act[i].ress = player->act[i + 1].ress;
	      player->act[i].timer = player->act[i + 1].timer;
	      player->act[i].timer_micro = player->act[i + 1].timer_micro;
	      i++;
	    }
	  if (i == 9)
	    {
	      player->act[i].id = 0;
	      player->act[i].timer = 0;
	      player->act[i].timer_micro = 0;
	    }
	  player->i_tim--;
	}
    }
}
