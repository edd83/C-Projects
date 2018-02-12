/*
** init_server.c for init_server in /home/lardet_e/TP/my_ftp/begin
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Apr  9 12:20:38 2014 lardet
** Last update Sat Apr 12 18:49:57 2014 lardet
*/

#include "server.h"

void			init_server(t_ftp *server, PORT port)
{
  int			on;

  memset(server, 0, sizeof(*server));
  if ((server->fd_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    my_error(errno, "socket()", 0);
  server->sin.sin_addr.s_addr = htonl(INADDR_ANY);
  server->sin.sin_family = AF_INET;
  server->sin.sin_port = htons(port);
  if ((setsockopt(server->fd_sock, SOL_SOCKET,
                  SO_REUSEADDR, (char *)&on, sizeof(server->fd_sock))) == -1)
    my_error(errno, "setsockopt()", 0);
  if (bind(server->fd_sock, (struct sockaddr *)&server->sin,
	   sizeof(server->sin)) == -1)
    my_error(errno, "bind()", 0);
  if (listen(server->fd_sock, 1) == -1)
    my_error(errno, "listen()", 0);
}
