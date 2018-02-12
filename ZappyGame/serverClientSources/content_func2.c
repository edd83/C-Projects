/*
** content_func2.c for zappy in /home/casoni_f/Projets/PSU_2013_zappy/serverClientSources
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Wed Jul  2 11:38:48 2014 Fabien Casoni
** Last update Sun Jul 20 17:52:15 2014 Fabien Casoni
*/

#include "server.h"

char		**fill_ress_tab()
{
  char		**tab;

  tab = malloc(sizeof(char **) * 50);
  tab[0] = "nourriture";
  tab[1] = "linemate";
  tab[2] = "deraumere";
  tab[3] = "sibur";
  tab[4] = "mendiane";
  tab[5] = "phiras";
  tab[6] = "thystame";
  return (tab);
}

void		check_ress_cli(int x, int y, char *buff, t_server *serv)
{
  t_ressources	*ress;
  char		b[412];
  char		**tab;

  ress = serv->ress;
  tab = fill_ress_tab();
  check_xy(&x, &y, serv);
  while (ress != NULL)
    {
      if ((int)ress->x == x && (int)ress->y == y &&
	  ress->flag == 1)
	{
	  sprintf(b, " %s", tab[ress->type_ress]);
	  strcat(buff, b);
	}
      ress = ress->next;
    }
}

void		check_player_cli(int *coord, unsigned int pid, char *buff,
				 t_server *serv)
{
  t_team	*team;
  t_player	*p;

  team = serv->begin_team;
  check_coord(coord, serv);
  while (team != NULL)
    {
      p = team->begin;
      while (p != NULL)
	{
	  if ((int)p->x == coord[0] && (int)p->y == coord[1]
	      && p->id != pid)
	    sprintf(buff, "%s player", buff);
	  p = p->next;
	}
      team = team->next;
    }
}

void		check_xy(int *x, int *y, t_server *serv)
{
  int		x2;
  int		y2;

  x2 = *x;
  y2 = *y;
  if (*x < 0)
    *x = (int)serv->map->x + x2;
  else if (*x > (int)serv->map->x)
    *x -= (int)serv->map->x - 1;
  if (*y < 0)
    *y = (int)serv->map->y + y2;
  else if (*y > (int)serv->map->y)
    *y -= (int)serv->map->y - 1;
}

void		check_coord(int *coord, t_server *serv)
{
  int		x;
  int		y;

  x = coord[0];
  y = coord[1];
  if (coord[0] < 0)
    coord[0] = (int)serv->map->x + x;
  else if (coord[0] > (int)serv->map->x)
    coord[0] -= (int)serv->map->x - 1;
  if (coord[1] < 0)
    coord[1] = (int)serv->map->y + y;
  else if (coord[1] > (int)serv->map->y)
    coord[1] -= (int)serv->map->y - 1;
}
