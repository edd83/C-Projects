/*
** accept_connection.c for accept_connection in /home/lardet_e/TP/my_ftp/begin
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Apr  9 16:37:12 2014 lardet
** Last update Sun Apr 13 23:00:48 2014 lardet
*/

#include "server.h"

void		init_req(t_server *req)
{
  req->cmd[0] = "ls\n";
  req->cmd[1] = "pwd\n";
  req->cmd[2] = "quit\n";
  req->func[0] = send_ls;
  req->func[1] = send_pwd;
  req->func[2] = send_quit;
}

void			exec_cmd(char *buffer, SOCKET csock, t_ftp *server)
{
  int			i;
  t_server		req;

  i = 0;
  init_req(&req);
  while (i < 3)
    {
      if (!strncmp(req.cmd[i], buffer, strlen(req.cmd[i]) - 1))
        {
          req.func[i](csock, buffer, server);
          return ;
        }
      ++i;
    }
  write(csock, "REQ NOTFOUND\n", strlen("REQ NOTFOUND\n"));
}

void			talk_to_client(t_ftp *server, SOCKET csock)
{
  char			buffer[4096];
  int			ret;

  bzero(buffer, sizeof(buffer));
  while ((ret = read(csock, buffer, 4096)))
    {
      if (ret < 1)
        my_error(errno, "read()", 0);
      printf("client with socket %d: %s\n", csock, buffer);
      exec_cmd(buffer, csock, server);
      bzero(buffer, sizeof(buffer));
    }
  printf("client with socket %d left\n", csock);
  if (close(csock) == -1)
    my_error(errno, "close()", 0);
}

void			accept_connection(t_ftp *server)
{
  socklen_t		caddrsize;
  struct sockaddr_in	csin;
  SOCKET		csock;
  int			pid;

  caddrsize = sizeof(csin);
  while (1)
    {
      if ((csock = accept(server->fd_sock, (struct sockaddr *)&csin,
			  &caddrsize)) == -1)
	my_error(errno, "accept()", 1);
      if ((pid = fork()) == -1)
        my_error(errno, "fork()", 1);
      if (pid == 0)
	talk_to_client(server, csock);
      else
	if (close(csock) == -1)
	  {
	    my_error(errno, "close()", 0);
	    exit(0);
	  }
    }
}
