/*
** manage_life_2.c for manage_life_2 in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Jul 10 23:13:16 2014 lardet
** Last update Thu Jul 10 23:13:36 2014 lardet
*/

#include "server.h"

void		manage_life_2_next(t_player *player, t_server *serv,
				   struct timeval tv, int temp)
{
  if ((player->life.tv_usec - temp) < 0)
    {
      player->life.tv_sec -= (serv->save_tv.tv_sec - tv.tv_sec);
      player->life.tv_usec = (1000000 - temp);
    }
  else
    {
      player->life.tv_sec -= (serv->save_tv.tv_sec - tv.tv_sec - 1);
      player->life.tv_usec -= temp;
    }
}
