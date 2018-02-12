/*
** parser.c for parser in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Jun 23 10:57:55 2014 lardet
** Last update Sun Jul 20 17:39:43 2014 lardet
*/

#include "server.h"

t_server		*pars_arg(int argc, char **argv)
{
  t_server		*serv;
  int			i;

  i = -1;
  if (argc < 12)
    return (NULL);
  if (strcmp(argv[1], "-p") != 0)
    return (NULL);
  if ((serv = malloc(sizeof(*serv))) == NULL)
    return (NULL);
  memset(serv, 0, sizeof(*serv));
  bzero((char*)&(serv->svrAdd), sizeof(serv->svrAdd));
  serv->svrAdd.sin_family = AF_INET;
  serv->svrAdd.sin_addr.s_addr = INADDR_ANY;
  serv->svrAdd.sin_port = htons(atoi(argv[2]));
  if (fill_map(argv, serv) == -1 || (i = fill_name(argv, serv)) == -1
      || fill_rest(argv, i, serv) == -1 || create_ress(argc, argv, serv) == -1
      || set_lvl_requirements(serv) == -1)
    return (NULL);
  return (serv);
}

int			fill_map(char **argv, t_server *serv)
{
  if (strcmp(argv[3], "-x") != 0 || strcmp(argv[5], "-y") != 0)
    return (-1);
  if (atoi(argv[4]) <= 0 || atoi(argv[6]) <= 0)
    return (-1);
  if ((serv->map = malloc(sizeof(*serv->map))) == NULL)
    return (-1);
  serv->map->x = atoi(argv[4]);
  serv->map->y = atoi(argv[6]);
  return (0);
}

int			fill_name(char **argv, t_server *serv)
{
  int			i;

  i = 7;
  if (strcmp(argv[i], "-n") != 0)
    return (-1);
  if ((serv->team = malloc(sizeof(*serv->team))) == NULL)
    return (-1);
  i++;
  while (strcmp(argv[i], "-c") != 0)
    {
      if (add_in_list_team(serv, argv[i]) == -1)
	return (-1);
      i++;
    }
  return (i);
}

int			fill_rest(char **argv, int i, t_server *serv)
{
  if (argv[i + 3] == NULL || argv[i + 1] == NULL || argv[i] == NULL
      || argv[i + 2] == NULL)
    return (-1);
  if ((strcmp(argv[i], "-c") != 0) || (strcmp(argv[i + 2], "-t") != 0))
    return (-1);
  if ((atoi(argv[i + 1]) <= 0) || (atoi(argv[i + 3]) <= 0))
    return (-1);
  serv->nb_client_permitted = atoi(argv[i + 1]);
  fill_nb_client_team(serv);
  serv->delay = atoi(argv[i + 3]);
  return (0);
}
