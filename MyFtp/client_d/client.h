/*
** client.h for client in /home/lardet_e/TP/my_ftp/begin/client
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Apr 11 11:10:01 2014 lardet
** Last update Sun Apr 13 22:53:58 2014 lardet
*/

#ifndef _CLIENT_H_
# define _CLIENT_H_

#include "../server/server.h"
#include "get_next_line.h"
#include "color.h"

typedef struct		s_ftp_client
{
  SOCKET		sock;
  char			*buffer;
}			t_ftp_client;

typedef struct		s_client_req
{
  const char		*cmd[4];
  void			(*func[4])(t_ftp_client *);
}			t_client;

int			exec_request(t_ftp_client *client, char *buffer);
void                    init_client(char *, char*, t_ftp_client *client);
void                    rcv_ls(t_ftp_client *client);
void                    rcv_pwd(t_ftp_client *client);
void                    rcv_quit(t_ftp_client *client);
void                    rcv_err(t_ftp_client *client);
void                    rcv_success(t_ftp_client *client);
void			puts_color(char *s, char *color);

#endif
