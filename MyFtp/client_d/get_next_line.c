/*
** get_next_line.c for get_next_line in /home/volpe_p/rendu/CPE_2013_getnextline
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Thu Nov 28 11:20:55 2013 volpe
** Last update Sun Mar  9 13:28:26 2014 lardet
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	my_fd_error(const int fd)
{
  if (fd < 0)
    {
      write(2, "Error on file descriptor\n", 25);
      return (-1);
    }
  else
    return (0);
}

int	my_stock_buffer(char *buffer, char *buffer_add, int *j, int *nb_read)
{
  int	i;

  i = 0;
  while (buffer[*j] != '\0')
    {
      if (buffer[*j] == '\n')
	{
	  buffer_add[i] = 0;
	  i = i + 1;
	  if ((*j + 1) < *nb_read)
	    *j = *j + 1;
	  else
	    *j = 0;
	  return (0);
	}
      buffer_add[i] = buffer[*j];
      i = i + 1;
      *j = *j + 1;
    }
  buffer_add[i] = 0;
  *j = 0;
  return (0);
}

char		*get_next_line(const int fd)
{
  char		buffer[BUFF_SIZE];
  static int	j;
  static int	nb_read;
  static char	*buffer_add;

  if ((buffer_add = malloc(BUFF_SIZE)) == NULL) {
      write(2, "Error on malloc\n", 16);
      return (NULL);
    }
  if (my_fd_error(fd) == -1)
    return (NULL);
  while (BUFF_SIZE -1 > 0)
    {
      if (j == 0)
	{
	  if ((nb_read = read(fd, buffer, BUFF_SIZE - 1)) <= 0)
	    return (NULL);
	  buffer[nb_read] = 0;
	}
      if (my_stock_buffer(buffer, buffer_add, &j, &nb_read) == 0)
	return (buffer_add);
      else
	return (NULL);
    }
  return (buffer_add);
}
