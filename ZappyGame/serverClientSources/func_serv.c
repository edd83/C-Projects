/*
** func_serv.c for func_serv in /home/lardet_e/zappy
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed May  7 15:26:44 2014 lardet
** Last update Sat Jul 19 15:20:09 2014 lardet
*/

#include	"server.h"

int			on = 1;

void			sigint_handler(int sig)
{
  printf("Server stopped manually with signal %d (Ctrl+C).\n", sig);
  on = 0;
}

int			launcher(t_server *serv)
{
  int			connFd;

  if (init(serv) == -1)
    return (-1);
  serv->t[0] = serv->listenFd;
  serv->nb_client = 1;
  signal(SIGINT, sigint_handler);
  while (on)
    {
      if (init_select(serv) == -1)
	return (-1);
      if ((connFd = init_accept(serv)) == -1)
	return (-1);
      if (print_message(serv) == -1)
	return (-1);
    }
  if (close(connFd) == -1)
    return (-1);
  return (0);
}

t_communication		*init_comm()
{
  static t_communication	com;

  com.list[0] = "msz\n";
  com.list[1] = "bct X Y\n";
  com.list[2] = "mct\n";
  com.list[3] = "tna\n";
  com.list[4] = "ppo #n\n";
  com.list[5] = "plv #n\n";
  com.list[6] = "pin #n\n";
  com.list[7] = "sgt\n";
  com.list[8] = "sst T\n";
  com.func_ptr[0] = &size_map;
  com.func_ptr[1] = &content_case;
  com.func_ptr[2] = &content_map;
  com.func_ptr[3] = &name_team;
  com.func_ptr[4] = &position_player;
  com.func_ptr[5] = &level_player;
  com.func_ptr[6] = &inventory_player;
  com.func_ptr[7] = &ask_time_unit;
  com.func_ptr[8] = &update_time_unit;
  return (&com);
}

int			communication(char *buff, int t, t_server *serv)
{
  int			i;
  int			ok;
  t_communication	*com;

  ok = -1;
  i = 0;
  com = init_comm();
  if (t == serv->fd_graphic || !serv->fd_graphic)
    while (i < 9 && ok == -1)
      {
	if (strncmp(com->list[i], buff, 3) == 0)
	  ok = (*(com->func_ptr[i]))(buff, serv->fd_graphic, serv);
	if (!serv->fd_graphic)
	  if (strcmp(buff, "GRAPHIC\n") == 0)
	    ok = init_graphic(buff, t, serv);
	i++;
      }
  if (t != serv->fd_graphic)
    ok = next_check(ok, buff, t, serv);
  if (ok == -1 && send(t, "suc\n", 4, 0) == -1)
    return (-1);
  else if (ok == -2 && send(t, "sbp\n", 4, 0) == -1)
    return (-1);
  return (0);
}

int		init_graphic(char *buff, int t, t_server *serv)
{
  serv->fd_graphic = t;
  sprintf(buff, "%s\n", "msz");
  size_map(buff, t, serv);
  sprintf(buff, "%s\n", "sgt");
  ask_time_unit(buff, t, serv);
  sprintf(buff, "%s\n", "mct");
  content_map(buff, t, serv);
  name_team(buff, t, serv);
  return (0);
}
