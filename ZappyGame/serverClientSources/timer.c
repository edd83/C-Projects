/*
** timer.c for timer in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Jul  3 12:05:31 2014 lardet
** Last update Sun Jul 20 16:12:41 2014 lardet
*/

#include "server.h"

void			sub_check_timer(t_player *player, t_server *serv)
{
  int			temp;

  if (player->act[0].timer == serv->save_tv.tv_sec
      && player->act[0].timer_micro == serv->save_tv.tv_usec)
    {
      player->act[0].timer -= serv->save_tv.tv_sec;
      player->act[0].timer_micro -= serv->save_tv.tv_usec;
      manage_life_3(player, serv);
      reorder_array_player(player, serv);
    }
  else if (player->act[0].timer_micro < serv->save_tv.tv_usec)
    {
      temp = (1000000 - ((player->act[0].timer_micro - serv->save_tv.tv_usec)
			 * - 1));
      player->act[0].timer -= (serv->save_tv.tv_sec + 1);
      player->act[0].timer_micro = temp;
      manage_life_4(player, temp, serv);
    }
  else
    {
      player->act[0].timer -= serv->save_tv.tv_sec;
      player->act[0].timer_micro -= serv->save_tv.tv_usec;
      temp = player->act[0].timer_micro;
      manage_life_5(player, serv);
    }
}

void			sub_timer(t_player *player, t_server *serv,
				  struct timeval tv, int temp)
{
  temp = ((player->act[0].timer_micro - (serv->save_tv.tv_usec -
					     tv.tv_usec)));
  if (temp < 0 && temp < 1000000)
	temp = 1000000 + temp;
  if (player->act[0].timer - (serv->save_tv.tv_sec - tv.tv_sec) >= 0)
    {
      player->act[0].timer -= (serv->save_tv.tv_sec - tv.tv_sec);
      player->act[0].timer_micro = temp;
      manage_life_2(player, temp, serv, tv);
    }
  else
    manage_life_2(player, temp, serv, tv);
}

void			sub_check_timer_tv(t_player *player, struct timeval tv,
					   t_server *serv)
{
  int			temp;

  if (player->act[0].timer_micro < tv.tv_usec)
    {
      temp = ((player->act[0].timer_micro - (serv->save_tv.tv_usec -
					     tv.tv_usec)));
      if (temp < 0 && temp < 1000000)
	{
	  temp = 1000000 + temp;
	  player->act[0].timer -= ((serv->save_tv.tv_sec - tv.tv_sec) + 1);
	}
      else
	player->act[0].timer -= (serv->save_tv.tv_sec - tv.tv_sec);
      player->act[0].timer_micro = temp;
      manage_life_1(player, temp, serv, tv);
    }
  else
    {
      temp = 0;
      sub_timer(player, serv, tv, temp);
    }
}

void			sub_all_timer(t_server *serv)
{
  t_player		*next;
  t_player		*player;
  t_team		*team;

  team = serv->begin_team;
  while (team)
    {
      player = team->begin;
      while (player)
	{
	  next = player->next;
	  sub_check_timer(player, serv);
	  player = next;
	}
      team = team->next;
    }
}

void			sub_all_timer_tv(t_server *serv, struct timeval tv)
{
  t_player		*next;
  t_player		*player;
  t_team		*team;

  team = serv->begin_team;
  while (team)
    {
      player = team->begin;
      while (player)
	{
	  next = player->next;
	  sub_check_timer_tv(player, tv, serv);
	  player = next;
	}
      team = team->next;
    }
}
