/*
** main.c for main in /home/lardet_e/TP/my_ftp/begin/client
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Apr 11 10:58:54 2014 lardet
** Last update Sun Apr 13 23:24:47 2014 lardet
*/

#include "client.h"

void		init_req(t_client *req)
{
  req->cmd[0] = "REQ NOTFOUND\n";
  req->cmd[1] = "REQ SUCCESS\n";
  req->cmd[2] = "ls\n";
  req->cmd[3] = "pwd\n";
  req->func[0] = rcv_err;
  req->func[1] = rcv_success;
  req->func[2] = rcv_ls;
  req->func[3] = rcv_pwd;
}

int		exec_request(t_ftp_client *client, char *buffer)
{
  t_client	req;
  int		i;

  i = 0;
  init_req(&req);
  while (i < 4)
    {
      if (buffer && !strncmp(req.cmd[i], buffer, strlen(req.cmd[i]) - 1))
	req.func[i](client);
      else if (!strncmp("quit\n", buffer, strlen("quit\n") - 1))
	{
	  xwrite(1, "Bye Bye!!!\n", strlen("Bye Bye!!!\n"));
	  if (close(client->sock) == -1)
	    my_error(errno, "close()", 0);
	  req.func[1](client);
	  return (-1);
	}
      ++i;
    }
  return (0);
}

int		read_req(t_ftp_client *client)
{
  char		*buf;

  buf = get_next_line(client->sock);
  if (exec_request(client, buf) == -1)
    return (-1);
  free(buf);
  return (0);
}

int		launcher(char *ip, char *port)
{
  t_ftp_client	client;
  char		buffer[4096];
  int		ret;

  init_client(ip, port, &client);
  while (1)
    {
      bzero(buffer, 4096);
      puts_color("client -> ", YELLOW);
      if ((ret = read(0, buffer, 4096)) < 1)
	{
	  if (close(client.sock) == -1)
	    my_error(errno, "close()", 0);
	  my_error(errno, "read()", 0);
	}
      else if (buffer[0] == '\n')
	continue ;
      buffer[ret - 1] = 0;
      xwrite(client.sock, buffer, strlen(buffer));
      if (read_req(&client) == -1)
	return (-1);
    }
  return (0);
}

int		main(int ac, char **av)
{
  if (ac != 3)
    {
      fprintf(stderr, "Usage: ./client ip port\n");
      return (0);
    }
  if (launcher(av[1], av[2]) == -1)
    return (1);
  return (0);
}
