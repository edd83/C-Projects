/*
** func_team.c for func_team in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Jun 27 10:14:58 2014 lardet
** Last update Sat Jul 19 15:13:53 2014 lardet
*/

#include "server.h"

int		team_exist(char *buff, t_server *serv)
{
  t_team	*team;
  char		str[4096];

  team = serv->begin_team;
  while (team != NULL)
    {
      sprintf(str, "%s\n", team->name);
      if (strcmp(str, buff) == 0)
	return (0);
      team = team->next;
    }
  return (-1);
}

t_team		*team_check(char *buff, t_server *serv)
{
  t_team	*team;
  char		str[4096];

  team = serv->begin_team;
  while (team != NULL)
    {
      sprintf(str, "%s\n", team->name);
      if (strcmp(str, buff) == 0)
	return (team);
      team = team->next;
    }
  return (NULL);
}

int			add_in_list_team(t_server *serv, char *name)
{
  t_team		*elem;
  t_team		*elem2;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  memset(elem, 0, sizeof(*elem));
  if (serv->begin_team == NULL)
    {
      elem->name = name;
      elem->next = NULL;
      serv->begin_team = elem;
    }
  else
    {
      elem2 = serv->begin_team;
      while (elem2->next != NULL)
	elem2 = elem2->next;
      elem->name = name;
      elem->next = NULL;
      elem2->next = elem;
    }
  return (0);
}

void			fill_nb_client_team(t_server *serv)
{
  t_team		*team;

  team = serv->begin_team;
  while (team)
    {
      team->nb_client_permitted = serv->nb_client_permitted;
      team = team->next;
    }
}

int		team_is_ok(char *buff, t_team *team)
{
  char		str[4096];

  sprintf(str, "%s\n", team->name);
  if (strcmp(str, buff) == 0)
    return (0);
  return (-1);
}
