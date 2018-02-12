/*
** player_actions.c for player_actions in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Jul  2 10:58:08 2014 lardet
** Last update Sat Jul 19 12:13:05 2014 lardet
*/

#include "server.h"

int				inventory(char *buff, int fd, t_server *serv)
{
  t_player			*player;

  if ((player = search_player_by_fd(fd, serv)) == NULL)
    return (-1);
  (void)buff;
  fill_timeout(player, 1, serv, 5);
  return (0);
}

int				take(char *buff, int fd, t_server *serv)
{
  char				**args;
  char				**tab;
  int				i;
  int				ok;
  t_player			*play;

  ok = -1;
  i = -1;
  if ((play = search_player_by_fd(fd, serv)) == NULL)
    return (-1);
  if ((args = strtowordtab(buff)) == NULL || !args[1])
    return (-1);
  tab = fill_tab();
  while (tab[++i] && ok == -1)
    {
      if (strcmp(tab[i], args[1]) == 0)
	ok = add_in_inventory(i, serv, play);
    }
  if (ok == -1)
    {
      play->act[play->i_tim].ress = -1;
      fill_timeout(play, 7, serv, 6);
    }
  return (0);
}

int				add_in_inventory(unsigned int i, t_server *serv,
						 t_player *player)
{
  int		find;
  t_ressources	*ress;

  find = -1;
  ress = serv->begin_ress;
  while (ress != NULL && find == -1)
    {
      if (player->x == ress->x && ress->flag == 1 &&
	  player->y == ress->y && ress->type_ress == i)
	{
	  if (player->i_tim <= 9)
	    player->act[player->i_tim].ress = i;
	  fill_timeout(player, 7, serv, 6);
	  player->inventory[i] += 1;
	  if (i == 0)
	    update_life_with_add(player, serv);
	  find = 0;
	  ress->flag = 0;
	}
      ress = ress->next;
    }
  return (find);
}

int				put(char *buff, int fd, t_server *serv)
{
  char				**args;
  char				**tab;
  unsigned int			i;
  int				ok;
  t_player			*play;

  ok = -1;
  i = 0;
  if ((play = search_player_by_fd(fd, serv)) == NULL)
    return (-1);
  if ((args = strtowordtab(buff)) == NULL || !args[1])
    return (-2);
  tab = fill_tab();
  while (tab[i] && ok == -1)
    {
      if (strcmp(tab[i], args[1]) == 0)
	ok = put_down(i, fd, serv);
      i++;
    }
  if (ok == -1)
    {
      play->act[play->i_tim].ress = -1;
      fill_timeout(play, 7, serv, 6);
    }
  return (0);
}

int				put_down(int i, int fd, t_server *serv)
{
  t_player	*player;
  int		find;

  find = -1;
  if ((player = search_player_by_fd(fd, serv)) == NULL)
    return (-1);
  if (player->inventory[i] >= 1)
    {
      player->inventory[i] -= 1;
      create_pos_ress(serv, i, player->x, player->y);
      if (player->i_tim <= 9)
	player->act[player->i_tim].ress = i;
      if (i == 0)
	update_life_with_put(player, serv);
      fill_timeout(player, 7, serv, 7);
      find = 1;
    }
  return (find);
}
