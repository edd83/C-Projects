/*
** xfunction.c for xfunction in /home/lardet_e/TP/my_ftp/begin
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Apr 10 18:16:30 2014 lardet
** Last update Sun Apr 13 23:03:14 2014 lardet
*/

#include "client.h"

int                     xwrite(int fd, const void *buf, int len)
{
  int                   ret;

  if ((ret = write(fd, buf, len)) == -1)
    my_error(errno, "write()", 1);
  return (ret);
}
void                    *xmalloc(int size)
{
  void                  *ptr;
  int                   errno;

  errno = 0;
  ptr = malloc(size);
  if (!ptr)
    my_error(errno, "malloc()", 0);
  return (ptr);
}
