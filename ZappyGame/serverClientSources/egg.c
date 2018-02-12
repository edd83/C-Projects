/*
** egg.c for zappy in /home/casoni_f/Projets/PSU_2013_zappy/serverClientSources
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Mon Jul  7 15:28:31 2014 Fabien Casoni
** Last update Fri Jul 18 17:58:49 2014 Fabien Casoni
*/

#include "server.h"

int		find_free_id(t_server *serv)
{
  int		new_id;
  int		searching;
  t_team	*team;
  t_player	*p;

  new_id = 0;
  searching = 1;
  while	(searching)
    {
      team = serv->begin_team;
      while (team != NULL)
	{
	  p = team->begin;
	  while (p != NULL)
	    if (check_id(p, team, serv, &new_id))
	      p = p->next;
	  team = team->next;
	}
      searching = 0;
    }
  return (new_id);
}

int		check_id(t_player *p, t_team *team, t_server *serv, int *new_id)
{
  if ((int)p->id == *new_id)
    {
      team = serv->begin_team;
      p = team->begin;
      ++(*new_id);
      return (0);
    }
  return (1);
}

int		add_eggs(t_server *serv, int x, int y)
{
  t_egg		*new;
  t_egg		*head;
  int		id;

  id = find_free_id(serv);
  if (serv->team->egg_list == NULL &&
      (serv->team->egg_list = malloc(sizeof(*serv->team->egg_list))) != NULL)
    {
      serv->team->egg_list->x = x;
      serv->team->egg_list->y = y;
      serv->team->egg_list->id = id;
      serv->team->egg_list->next = NULL;
    }
  else if ((new = malloc(sizeof(*new))) != NULL)
    {
      head = serv->team->egg_list;
      while ((head = head->next) != NULL);
      new->x = x;
      new->y = y;
      new->id = id;
      new->next = NULL;
      head->next = new;
    }
  return (id);
}

int		fork_player(char *buff, int fd, t_server *serv)
{
  t_player	*player;
  int		len;

  if ((player = search_player_by_fd(fd, serv)) == NULL)
    return (-1);
  len = sprintf(buff, "pfk %d\n", (int)player->id);
  fill_timeout(player, 42, serv, 11);
  if (send(serv->fd_graphic, buff, len, 0) == -1)
    return (0);
  return (0);
}
