/*
** server.c for server in /home/lardet_e/zappy
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue May  6 12:49:09 2014 lardet
** Last update Fri Jul 18 13:42:05 2014 Fabien Casoni
*/

#include "server.h"

int			init(t_server *serv)
{
  serv->listenFd = socket(AF_INET, SOCK_STREAM, 0);
  if (serv->listenFd < 0)
    {
      dprintf(2, "Cannot open socket\n");
      return (-1);
    }
  if (bind(serv->listenFd, (struct sockaddr *)&(serv->svrAdd),
	   sizeof(serv->svrAdd)) < 0)
    {
      dprintf(2, "Cannot bind\n");
      return (-1);
    }
  listen(serv->listenFd, 10);
  return (serv->listenFd);
}

int			print_message(t_server *serv)
{
  int			i;
  char			buf[4096];

  i = 1;
  while (i < serv->nb_client)
    {
      if (FD_ISSET(serv->t[i], &(serv->readf)))
	{
	  if (recv(serv->t[i], &buf, 4096, 0) <= 0)
	    {
	      write(1, "Connection closed\n", 18);
	      if (close(serv->t[i]) == -1)
		{
		  dprintf(2, "Error on close\n");
		  return (-1);
		}
	      erase_fd(serv, serv->t[i]);
	    }
	  else
	    communication(buf, serv->t[i], serv);
	  memset(buf, '\0', 4096);
	}
      i++;
    }
  return (0);
}

int			init_select(t_server *serv)
{
  struct timeval	tv;
  int			j;
  int			sockmax;

  FD_ZERO(&(serv->readf));
  FD_SET(serv->listenFd, &(serv->readf));
  sockmax = serv->listenFd;
  j = 0;
  while (j < serv->nb_client)
    {
      if (serv->t[j] != 0)
	FD_SET(serv->t[j], &(serv->readf));
      if (sockmax < serv->t[j])
	sockmax = serv->t[j];
      j++;
    }
  tv = check_timer(serv);
  if (select(sockmax + 1, &(serv->readf), NULL, NULL, &tv) == -1)
    {
      dprintf(2, "Error on select");
      return (-1);
    }
  check_rest_timer(serv, tv);
  return (0);
}

int			init_accept(t_server *serv)
{
  struct sockaddr_in	clntAdd;
  socklen_t		len;
  int			connFd;

  len = sizeof(clntAdd);
  if (FD_ISSET(serv->listenFd, &(serv->readf)))
    {
      connFd = accept(serv->listenFd, (struct sockaddr *)&clntAdd, &len);
      if (connFd < 0)
	{
	  dprintf(2, "Cannot accept connection\n");
	  if (close(connFd) == -1)
	    return (-1);
	  return (-1);
	}
      if (send(connFd, "BIENVENUE\n", 10, 0) == -1)
	return (-1);
      serv->nb_client += 1;
      serv->t[serv->nb_client - 1] = connFd;
    }
  return (connFd);
}

int			main(int argc, char **argv)
{
  t_server		*serv;

  if ((serv = pars_arg(argc, argv)) == NULL)
    {
      printf("Usage : %s -p PORT -x WIDTH -y HEIGHT \
-n TEAM(S) NAME(S)... -c TEAM_MATES_NB -t DELAY\n", argv[0]);
      return (-1);
    }
  if (launcher(serv) == -1)
    return (-1);
  return (0);
}
