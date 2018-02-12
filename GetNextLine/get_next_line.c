/*
** get_next_line.c for get_next_line in /home/lardet_e/rendu/CPE_2013_getnextline
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Nov 28 23:46:49 2013 lardet
** Last update Sun Dec  1 22:32:26 2013 lardet
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	my_error_fd(int fd)
{
  if (fd < 0)
    {
      write(2, "Error on file desciptor!\n", 25);
      return (-1);
    }
  else
    return (0);
}

int	aff_strb(char *buff, char *add, int *j, int *nb_read)
{
  int	i;

  i = 0;
  while (buff[*j] != '\0')
    {
      if (buff[*j] == '\n')
	{
	  add[i] = '\0';
	  i = i + 1;
	  if ((*j + 1) >= *nb_read)
	    *j = 0;
	  else
	    *j = *j + 1;
	  return (1);
	}
      add[i] = buff[*j];
      i = i + 1;
      *j = *j + 1;
    }
  add[i] = '\0';
  *j = 0;
  return (1);
}

char		*get_next_line(const int fd)
{
  static int	j;
  static int	nb_read;
  static char	*add;
  int		i;
  char		buff[BUF_SIZE];

  i = 0;
  if (my_error_fd(fd) == -1)
    return (NULL);
  if ((add = malloc(BUF_SIZE)) == NULL)
    return (NULL);
  while (i < BUF_SIZE)
    {
      if (j == 0)
	{
	  if ((nb_read = read(fd, buff, BUF_SIZE)) <= 0)
	    return (NULL);
	}
      if (aff_strb(buff, add, &j, &nb_read) == 1)
	return (add);
      else
	return (NULL);
    }
  return (add);
}
