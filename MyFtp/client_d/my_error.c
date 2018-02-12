/*
** my_error.c for my_error in /home/lardet_e/TP/my_ftp/begin
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Apr 10 18:29:58 2014 lardet
** Last update Sun Apr 13 23:25:10 2014 lardet
*/

#include	"client.h"

void		my_error(int err, char *func, int what)
{
  fprintf(stderr, "error: %s: %s\n", func, strerror(err));
  if (what == 0)
    exit(1);
}
