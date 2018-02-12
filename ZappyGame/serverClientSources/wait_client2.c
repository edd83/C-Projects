/*
** wait_client2.c for wait_client2 in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Jul 19 10:03:45 2014 lardet
** Last update Sat Jul 19 10:07:53 2014 lardet
*/

#include "server.h"

void		if_wait_client2(t_team *team, int fd)
{
  if (team->i_wait <= 9 && fd_already_exist(fd, team))
    {
      team->wait_client[team->i_wait] = fd;
      team->wait_name[team->i_wait] = team->name;
      team->i_wait = team->i_wait + 1;
      team->all_fd[team->all_i] = fd;
      team->all_i = team->all_i + 1;
    }
}

t_team		*take_team(int fd, t_server *serv)
{
  t_team	*team;
  int		i;

  team = serv->begin_team;
  while (team != NULL)
    {
      i = 0;
      while (team->all_fd[i])
	{
	  if (team->all_fd[i] == fd)
	    return (team);
	  i++;
	}
      team = team->next;
    }
  return (NULL);
}

void		add_fd(t_team *team, int fd)
{
  int		i;

  i = 0;
  while (team->all_fd[i])
    {
      if (team->all_fd[i] == fd)
	return ;
      i++;
    }
  team->all_fd[team->all_i] = fd;
  team->all_i = team->all_i + 1;
}
