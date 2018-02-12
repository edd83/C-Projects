/*
** init_client.c for init_client in /home/lardet_e/TP/my_ftp/begin/client
** 
** Made by lardet
x** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Apr 11 11:17:52 2014 lardet
** Last update Sun Apr 13 22:52:58 2014 lardet
*/

#include "client.h"

void			init_client(char *ip, char *av_port, t_ftp_client *client)
{
  struct hostent	*hp;
  struct sockaddr_in	sin;
  PORT			port;

  memset(client, 0, sizeof(*client));
  port = atoi(av_port);
  if ((client->sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    my_error(errno, "socket()", 0);
  if ((hp = gethostbyname(ip)) == 0)
    my_error(errno, "gethostbyname()", 0);
  sin.sin_addr = *(struct in_addr *)(hp->h_addr_list[0]);;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if (connect(client->sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
    my_error(errno, "connect()", 0);
}
