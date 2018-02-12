/*
** manage_life.c for manage_life in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Jul  8 18:42:28 2014 lardet
** Last update Sun Jul 13 19:34:04 2014 Fabien Casoni
*/

#include "server.h"

void		manage_life_1(t_player *player, int temp, t_server *serv,
			    struct timeval tv)
{
  temp = ((player->life.tv_usec - (serv->save_tv.tv_usec - tv.tv_usec)));
  if (temp < 0 && temp < 1000000)
    {
      temp = 1000000 + temp;
      player->life.tv_sec -= ((serv->save_tv.tv_sec - tv.tv_sec) + 1);
    }
  else
    player->life.tv_sec -= (serv->save_tv.tv_sec - tv.tv_sec);
  player->life.tv_usec = temp;
  player->inventory[0] = (int)((player->life.tv_sec * serv->delay) / 126);
  if ((player->life.tv_sec <= 0 && player->life.tv_usec <= 0) ||
      player->life.tv_sec <= 0)
    player_die(player, serv);
}

void		manage_life_2(t_player *player, int temp, t_server *serv,
			    struct timeval tv)
{
  temp = 1000000 - tv.tv_usec;
  if (temp < 0)
    {
      if (temp == 0)
	{
	  player->life.tv_sec -= (serv->save_tv.tv_sec - tv.tv_sec - 1);
	  player->life.tv_usec -= temp;
	}
      else
	{
	  temp = 1000000 + temp;
	  player->life.tv_sec -= (serv->save_tv.tv_sec - tv.tv_sec);
	  player->life.tv_usec -= temp;
      }
    }
  else if (temp < 1000000)
    manage_life_2_next(player, serv, tv, temp);
  player->inventory[0] = (int)((player->life.tv_sec * serv->delay) / 126);
  if ((player->life.tv_sec <= 0 && player->life.tv_usec <= 0) ||
      player->life.tv_sec <= 0)
    player_die(player, serv);
}

void		manage_life_3(t_player *player, t_server *serv)
{
  if ((player->life.tv_usec - serv->save_tv.tv_usec) <= 0)
    {
      player->life.tv_sec -= (serv->save_tv.tv_sec + 1);
      if ((player->life.tv_usec - serv->save_tv.tv_usec) < 0)
	player->life.tv_usec = (1000000 - serv->save_tv.tv_usec);
      else
	player->life.tv_usec = 0;
    }
  else
    {
      player->life.tv_sec -= serv->save_tv.tv_sec;
      player->life.tv_usec -= serv->save_tv.tv_usec;
    }
  player->inventory[0] = (int)((player->life.tv_sec * serv->delay) / 126);
  if ((player->life.tv_sec <= 0 && player->life.tv_usec <= 0) ||
      player->life.tv_sec <= 0)
    player_die(player, serv);
}

void		manage_life_4(t_player *player, int temp, t_server *serv)
{
  temp = (1000000 - (player->life.tv_usec - serv->save_tv.tv_usec));
  player->life.tv_sec -= (serv->save_tv.tv_sec + 1);
  player->life.tv_usec = temp;
  player->inventory[0] = (int)((player->life.tv_sec * serv->delay) / 126);
  if ((player->life.tv_sec <= 0 && player->life.tv_usec <= 0) ||
      player->life.tv_sec <= 0)
    player_die(player, serv);
}

void		manage_life_5(t_player *player, t_server *serv)
{
  player->life.tv_sec -= serv->save_tv.tv_sec;
  player->life.tv_usec -= serv->save_tv.tv_usec;
  player->inventory[0] = (int)((player->life.tv_sec * serv->delay) / 126);
  if ((player->life.tv_sec <= 0 && player->life.tv_usec <= 0) ||
      player->life.tv_sec <= 0)
    player_die(player, serv);
}
