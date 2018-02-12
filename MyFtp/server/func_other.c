/*
** func_other.c for func_other in /home/lardet_e/TP/my_ftp/begin
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Apr 10 18:11:43 2014 lardet
** Last update Sun Apr 13 23:02:33 2014 lardet
*/

#include "server.h"

void		send_pwd(SOCKET csock, char *buffer, t_ftp *server)
{
  int                   pid;
  int                   status;

  (void)buffer;
  (void)server;
  xwrite(csock, "pwd\n", strlen("pwd\n"));
  if ((pid = fork()) == -1)
    my_error(errno, "fork()", 1);
  if (pid == 0)
    {
      dup2(csock, 1);
      execlp("pwd", "pwd", NULL);
      my_error(errno, "execlp()", 1);
      xwrite(csock, "REQ NOTFOUND\n", strlen("REQ NOTFOUND\n"));
      exit(1);
    }
  if (wait(&status) < 0)
    my_error(errno, "wait()", 0);
  xwrite(csock, "REQ SUCCESS\n", strlen("REQ SUCCESS\n"));
}

void		send_ls(SOCKET csock, char *buffer, t_ftp *server)
{
  int                   pid;
  int                   status;

  (void)server;
  if (strcmp("ls", buffer) != 0)
    {
      xwrite(csock, "REQ NOTFOUND\n", strlen("REQ NOTFOUND\n"));
      return ;
    }
  xwrite(csock, "ls\n", strlen("ls\n"));
  if ((pid = fork()) == -1)
    my_error(errno, "fork()", 1);
  if (pid == 0)
    {
      dup2(csock, 1);
      if (execlp("ls", "ls", "-la", NULL) == -1)
	{
	  my_error(errno, "execlp()", 1);
	  xwrite(csock, "REQ NOTFOUND\n", strlen("REQ NOTFOUND\n"));
	}
      exit(1);
    }
  if (wait(&status) < 0)
    my_error(errno, "wait()", 0);
  xwrite(csock, "REQ SUCCESS\n", strlen("REQ SUCCESS\n"));
}

void		send_quit(SOCKET csock, char *buffer, t_ftp *server)
{
  (void)buffer;
  (void)server;
  xwrite(csock, "quit\n", strlen("quit\n"));
  printf("client with socket %d: socket closed\n", csock);
  if (close(csock) == -1)
    my_error(errno, "close()", 0);
  exit(0);
}
