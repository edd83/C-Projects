/*
** others_events.c for others_events in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Jun 27 14:38:16 2014 lardet
** Last update Sun Jul 20 17:28:03 2014 Fabien Casoni
*/

#include "server.h"

t_communication2		*init_event()
{
  static t_communication2	com;

  com.list[0] = "avance\n";
  com.list[1] = "gauche\n";
  com.list[2] = "droite\n";
  com.list[3] = "voir\n";
  com.list[4] = "inventaire\n";
  com.list[5] = "expulse\n";
  com.list[6] = "broadcast ";
  com.list[7] = "incantation\n";
  com.list[8] = "fork\n";
  com.list[9] = "prend";
  com.list[10] = "pose ";
  com.func_ptr[0] = &advance;
  com.func_ptr[1] = &left;
  com.func_ptr[2] = &right;
  com.func_ptr[3] = &see;
  com.func_ptr[4] = &inventory;
  com.func_ptr[5] = &expluse;
  com.func_ptr[6] = &broadcast;
  com.func_ptr[7] = &incantation;
  com.func_ptr[8] = &fork_player;
  com.func_ptr[9] = &take;
  com.func_ptr[10] = &put;
  return (&com);
}

int				others_events(char *buff, int fd, t_server *serv)
{
  t_communication2		*com;
  int				i;
  int				ok;

  ok = -1;
  i = 0;
  com = init_event();
  while (i < 11 && ok == -1)
    {
      if (strcmp(com->list[i], buff) == 0)
	ok = (*(com->func_ptr[i]))(buff, fd, serv);
      else if ((strncmp(com->list[i], buff, 5) == 0 && (i == 9 || i == 10))
	       || (strncmp(com->list[i], buff, 10) == 0 && i == 6))
	ok = (*(com->func_ptr[i]))(buff, fd, serv);
      i++;
    }
  if (ok == -1)
    return (-1);
  if (ok == -2)
    return (-2);
  return (0);
}

int				next_check(int ok, char *buff, int t,
					   t_server *serv)
{
  t_team			*team;

  if (ok != 0)
    {
      if (team_exist(buff, serv) == 0 || team_exist_with_fd(t, serv) != NULL)
	{
	  if ((team = team_check(buff, serv)) == NULL)
	    if ((team = take_team(t, serv)) == NULL)
	      return (-2);
	  if (team->nb_client_permitted <= 0)
	    {
	      if (if_wait_client(buff, t, serv, team) == 0)
		return (0);
	      else
		ok = func_player(buff, t, serv);
	    }
	  else
	    ok = next_check2(team, serv, buff, t);
	}
      else
	ok = others_events(buff, t, serv);
    }
  return (ok);
}

char				**fill_tab()
{
  char				**tab;

  tab = malloc(sizeof(char **) * 50);
  tab[0] = "nourriture\n";
  tab[1] = "linemate\n";
  tab[2] = "deraumere\n";
  tab[3] = "sibur\n";
  tab[4] = "mendiane\n";
  tab[5] = "phiras\n";
  tab[6] = "thystame\n";
  return (tab);
}

int				next_check2(t_team *team, t_server *serv,
					    char *buff, int t)
{
  int				ok;

  ok = -1;
  if (team_exist(buff, serv) == 0)
    {
      ok = func_player(buff, t, serv);
      if (team->wait_client[0] != 0)
	reorder_waiting(team);
    }
  else
    {
      sprintf(buff, "%s\n", team->name);
      ok = func_player(buff, t, serv);
      reorder_waiting(team);
    }
  return (ok);
}
