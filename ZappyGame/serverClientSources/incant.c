/*
** incant.c for zappy in /home/casoni_f/Projets/PSU_2013_zappy/serverClientSources
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Sat Jul  5 14:45:11 2014 Fabien Casoni
** Last update Sun Jul 20 16:38:05 2014 Fabien Casoni
*/

#include	"server.h"

int		check_incant_ress(t_server *serv, t_player *player)
{
  t_ressources	*ress;
  int		data[7];
  int		i;

  ress = serv->ress;
  i = -1;
  while (++i < 7)
    data[i] = 0;
  i = 0;
  while (ress != NULL)
    {
      if (ress->x == player->x && ress->y == player->y &&
	  ress->flag == 1 && ress->type_ress > FOOD)
	data[ress->type_ress] += 1;
      ress = ress->next;
    }
  while (++i < 7)
    if (data[i] != serv->lvl_req[player->level - 1][i])
      return (0);
  return (1);
}

int		check_incant_player(t_server *serv, t_player *pl, char *b)
{
  t_team	*team;
  t_player	*p;
  int		nb;

  nb = 0;
  team = serv->begin_team;
  sprintf(b, "pic %d %d %d", (int)pl->x, (int)pl->y, (int)pl->level);
  while (team != NULL)
    {
      p = team->begin;
      while (p != NULL)
	{
	  if (p->x == pl->x && p->y == pl->y)
	    {
	      nb += 1;
	      sprintf(b, "%s %d", b, (int)p->id);
	    }
	  p = p->next;
	}
      team = team->next;
    }
  sprintf(b, "%s\n", b);
  if (serv->lvl_req[pl->level - 1][0] != nb)
    return (0);
  return (1);
}

void		level_up_players(t_server *serv, t_player *player)
{
  t_team	*team;
  t_player	*p;

  team = serv->begin_team;
  while (team != NULL)
    {
      p = team->begin;
      while (p != NULL)
	{
	  if (p->x == player->x && p->y == player->y
	      && p->level == player->level)
	    p->level += 1;
	  p = p->next;
	}
      team = team->next;
    }
}

void		clean_ress(t_server *serv, t_player *player)
{
  t_ressources	*ress;

  ress = serv->begin_ress;
  while (ress != NULL)
    {
      if (ress->x == player->x && ress->y == player->y
	  && ress->flag == 1)
	ress->flag = 0;
      ress = ress->next;
    }
}

int		lvl_up_exec(t_player *player, t_server *serv)
{
  char		buff[4096];
  char		b2[4096];
  int		len;
  int		len2;

  memset(buff, 0, 4096);
  memset(b2, 0, 4096);
  if (check_incant_player(serv, player, buff)
      && check_incant_ress(serv, player))
    {
      clean_ress(serv, player);
      level_up_players(serv, player);
      len = sprintf(buff, "niveau actuel : %d\n", (int)player->level);
      len2 = sprintf(b2, "pie %d %d 1\n", player->x, player->y);
    }
  else
    {
      len = sprintf(buff, "niveau actuel : %d\n", (int)player->level);
      len2 = sprintf(b2, "pie %d %d 0\n", player->x, player->y);
    }
  if (send(player->fd, buff, len, 0) == -1 ||
      send(serv->fd_graphic, b2, len2, 0) == -1)
    return (-1);
  return (0);
}
