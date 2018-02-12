/*
** func_other.c for func_other in /home/lardet_e/TP/my_ftp/begin/client
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Apr 11 13:22:49 2014 lardet
** Last update Sun Apr 13 22:54:54 2014 lardet
*/

#include "client.h"

void		rcv_pwd(t_ftp_client *client)
{
  char                  *buffer;
  char                  *ret;
  int                   i;

  buffer = xmalloc(sizeof(*buffer) * 4096);
  bzero(buffer, 4096);
  while (42)
    {
      if (read(client->sock, buffer, 4096) < 0)
        my_error(errno, "read():", 0);
      if ((ret = strstr(buffer, "REQ SUCCESS\n")))
        break ;
      if ((ret = strstr(buffer, "REQ NOTFOUND\n")))
        {
          i = -2;
          break ;
        }
      puts_color(buffer, WHITE);
      bzero(buffer, 4096);
    }
  exec_request(client, ret);
  if (i == -2)
    if (read(client->sock, buffer, 4096) < 0)
      my_error(errno, "read():", 0);
  free(buffer);
}

void		rcv_ls(t_ftp_client *client)
{
  char                  *buffer;
  char                  *ret;
  int                   i;

  buffer = xmalloc(sizeof(*buffer) * 4096);
  bzero(buffer, 4096);
  while (42)
    {
      if (read(client->sock, buffer, 4096) < 0)
	my_error(errno, "read():", 0);
      if ((ret = strstr(buffer, "REQ SUCCESS\n"))
	  || (ret = strstr(buffer, "REQ NOTFOUND\n")))
	{
	  i = -1;
	  while (buffer[++i] && (buffer + i) != ret)
	    write(1, &buffer[i], 1);
	  break;
	}
      puts_color(buffer, WHITE);
      bzero(buffer, 4096);
    }
  exec_request(client, ret);
  free(buffer);
}

void		rcv_quit(t_ftp_client *client)
{
  char                  *buffer;
  char                  *ret;
  int                   i;

  buffer = xmalloc(sizeof(*buffer) * 4096);
  bzero(buffer, 4096);
  while (42)
    {
      if (read(client->sock, buffer, 4096) < 0)
	my_error(errno, "read():", 0);
      if ((ret = strstr(buffer, "REQ SUCCESS\n"))
	  || (ret = strstr(buffer, "REQ NOTFOUND\n")))
	{
	  i = -1;
	  while (buffer[++i] && (buffer + i) != ret)
	    write(1, &buffer[i], 1);
	  break ;
	}
      puts_color(buffer, WHITE);
      bzero(buffer, 4096);
    }
  free(buffer);
  close(client->sock);
  exit(0);
}

void		rcv_err(t_ftp_client *client)
{
  (void)client;
  puts_color("Requete not found\n", RED);
}

void		rcv_success(t_ftp_client *client)
{
  (void)client;
  puts_color("Requete success\n", GREEN);
}
