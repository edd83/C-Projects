/*
** wait_client.c for wait_client in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Jul 12 18:24:24 2014 lardet
** Last update Sat Jul 19 10:06:36 2014 lardet
*/

#include "server.h"

int		fd_already_exist(int fd, t_team *team)
{
  int		i;

  i = 0;
  while (team->wait_client[i])
    {
      if (team->wait_client[i] == fd)
	return (0);
      i++;
    }
  return (1);
}

t_team		*team_exist_with_fd(int fd, t_server *serv)
{
  t_team	*team;
  t_player	*player;
  int		find;

  find = 0;
  team = serv->begin_team;
  while (team && find == 0)
    {
      player = team->begin;
      while (player)
	{
	  if (fd == player->fd)
	    find = 1;
	  player = player->next;
	}
      if (team->wait_client[0])
	return (team);
      team = team->next;
    }
  return (NULL);
}

int		if_wait_client(char *buff, int fd, t_server *serv, t_team *team)
{
  if (team->nb_client_permitted <= 0)
    if_wait_client2(team, fd);
  else
    {
      if (team->wait_client[0] != 0)
	{
	  func_player(team->wait_name[0], team->wait_client[0], serv);
	  reorder_waiting(team);
	}
      else
	func_player(buff, fd, serv);
    }
  return (0);
}

void		reorder_waiting(t_team *team)
{
  int		i;

  i = 0;
  while (team->wait_client[i] && i < 9)
    {
      team->wait_client[i] = team->wait_client[i + 1];
      team->wait_name[i] = team->wait_name[i + 1];
      i++;
    }
  team->wait_client[i] = 0;
  team->wait_name[i] = NULL;
  team->i_wait -= 1;
}
