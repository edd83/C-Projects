/*
** check_timer.c for check_timer in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Jul  7 23:17:47 2014 lardet
** Last update Sun Jul 20 16:12:20 2014 lardet
*/

#include "server.h"

void			check_rest_timer(t_server *serv, struct timeval tv)
{
  if (tv.tv_sec == 0 && tv.tv_usec == 0)
    {
      sub_all_timer(serv);
      reorder_array(serv);
    }
  else
    {
      sub_all_timer_tv(serv, tv);
      reorder_array(serv);
    }
}

void			check_timer_player(t_server *serv, int *seconde,
					   int *micro_sec)
{
  t_player		*player;
  t_team		*team;

  team = serv->begin_team;
  while (team)
    {
      player = team->begin;
      while (player)
	{
	  if (player->i_tim > 0)
	    {
	      if (*seconde >= player->act[0].timer && player->act[0].timer >= 0)
		{
		  if (player->act[0].timer_micro >= 0)
		    {
		      *micro_sec = player->act[0].timer_micro;
		      *seconde = player->act[0].timer;
		    }
		}
	    }
	  player = player->next;
	}
      team = team->next;
    }
}

struct timeval		check_timer(t_server *serv)
{
  struct timeval	tv;
  int			seconde;
  int			micro_sec;

  seconde = 60;
  micro_sec = 0;
  check_timer_player(serv, &seconde, &micro_sec);
  tv.tv_sec = seconde;
  tv.tv_usec = micro_sec;
  serv->save_tv.tv_sec = seconde;
  serv->save_tv.tv_usec = micro_sec;
  return (tv);
}

void		        fill_timeout(t_player *player, int nb, t_server *serv,
				     int id)
{
  float			temp;

  temp = (float)nb / (float)serv->delay;
  if (player->i_tim <= 9)
    {
      player->act[player->i_tim].id = id;
      player->act[player->i_tim].timer = (int)temp;
      player->act[player->i_tim].timer_micro = ((temp -(int)temp) *
						pow(10, 6));
      player->i_tim++;
    }
}
