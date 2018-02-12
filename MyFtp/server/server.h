/*
** server.h for server in /home/lardet_e/TP/my_ftp/begin
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Apr  9 12:02:47 2014 lardet
** Last update Sun Apr 13 23:00:06 2014 lardet
*/

#ifndef _SERVER_H_
# define _SERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

typedef int SOCKET;
typedef int PORT;

typedef struct		s_ftp_server
{
  struct sockaddr_in	sin;
  int			fd_sock;
  int			port;
  char			**login_pass;
} t_ftp;

typedef struct		s_server_req
{
  char			*cmd[3];
  void			(*func[3])(SOCKET, char *, t_ftp *);
} t_server;

void			*xmalloc(int);
void			my_error(int, char *, int);
void			init_server(t_ftp *, PORT);
void			accept_connection(t_ftp *);
int			xwrite(int, const void *, int);
void			send_ls(SOCKET, char *, t_ftp *);
void			send_pwd(SOCKET, char *, t_ftp *);
void			send_quit(SOCKET, char *, t_ftp *);

#endif
