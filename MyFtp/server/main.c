/*
** main.c for main in /home/lardet_e/TP/my_ftp/begin
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Apr  9 12:01:53 2014 lardet
** Last update Thu Apr 10 19:04:29 2014 lardet
*/

#include "server.h"

void                    print_welcome(void)
{
  printf("\n+-------------------------+\n");
  printf("+        Welcome          +\n");
  printf("+-------------------------+\n");
  printf("\nServer is running ...\nWaiting clients ...\n\n");
}

void		launcher(int port)
{
  t_ftp		server;

  init_server(&server, port);
  print_welcome();
  accept_connection(&server);
}

int		main(int ac, char **av)
{
  if (ac != 2)
    {
      fprintf(stderr, "Usage: ./server port\n");
      return (1);
    }
  launcher(atoi(av[1]));
  return (0);
}
