/*
** create.c for create in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Jun 26 10:12:10 2014 lardet
** Last update Wed Jul  9 14:15:21 2014 lardet
*/

#include "server.h"

int			create_random_ress(t_server *serv, type t, int x, int y)
{
  t_ressources		*new;
  t_ressources		*head;

  if (serv->ress == NULL && (serv->ress = malloc(sizeof(*serv->ress))) != NULL)
    {
      serv->ress->x = rand() % (x + 1);
      serv->ress->y = rand() % (y + 1);
      serv->ress->flag = 1;
      serv->ress->type_ress = t;
      serv->ress->next = NULL;
      serv->begin_ress = serv->ress;
    }
  else if ((new = malloc(sizeof(*new))) != NULL)
    {
      head = serv->begin_ress;
      while (head->next != NULL)
	head = head->next;
      new->x = rand() % (x + 1);
      new->y = rand() % (y + 1);
      new->flag = 1;
      new->type_ress = t;
      new->next = NULL;
      head->next = new;
    }
  return (1);
}

int			create_pos_ress(t_server *serv, type t, int x, int y)
{
  t_ressources		*new;
  t_ressources		*head;

  new = malloc(sizeof(*new));
  head = serv->begin_ress;
  while (head->next != NULL)
    head = head->next;
  new->x = x;
  new->y = y;
  new->flag = 1;
  new->type_ress = t;
  new->next = NULL;
  head->next = new;
  return (1);
}

int			create_ress(int ac, char **argv, t_server *serv)
{
  int			i;
  int			k;
  type			type;

  i = -1;
  k = -1;
  serv->ress = NULL;
  type = THYSTANE;
  srand(time(NULL));
  while (strcmp(argv[++i], "-c") != 0 && i <= ac);
  if (strcmp(argv[i], "-c") != 0)
    return (-1);
  while (type >= FOOD)
    {
      while (++k < (atoi(argv[i + 1]) * 10))
	if (create_random_ress(serv, type,
			       atoi(argv[4]), atoi(argv[6])) == -1)
	  return (-1);
      k = -1;
      if (type != FOOD)
	--type;
      else
	return (1);
    }
  return (1);
}

char		*fill_str(t_player *player)
{
  char		*str;

  if ((str = malloc(sizeof(char *) * 50)) == NULL)
    return (NULL);
  sprintf(str, "pin %d %d %d %d %d %d %d %d %d %d\n", player->id,
	  player->x, player->y, player->inventory[0],
	  player->inventory[1], player->inventory[2],
	  player->inventory[3], player->inventory[4],
	  player->inventory[5], player->inventory[6]);
  return (str);
}

void		manage_food(t_player *player, int i, int type)
{
  if (type == 1)
    {
      if (i == 0)
	player->inventory[i] += 126;
      else
	player->inventory[i] += 1;
    }
  else
    {
      if (i == 0)
	player->inventory[i] -= 126;
      else
	player->inventory[i] -= 1;
    }
}
