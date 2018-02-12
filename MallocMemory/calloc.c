/*
** calloc.c for calloc.c in /home/volpe_p/rendu/malloc
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Wed Feb 12 12:42:24 2014 volpe
** Last update Wed Feb 12 17:19:08 2014 volpe
*/

#include <unistd.h>
#include "malloc.h"

void	*calloc(size_t number, size_t size)
{
  void	*addr;
  char	*str;
  unsigned int	i;

  i = 0;
  addr = malloc(number * size);
  if (addr == NULL)
    return (addr);
  str = addr;
  while (i < number * size)
    {
      str[i] = 0;
      i++;
    }
  return (addr);
}
