/*
** malloc.c for malloc.c in /home/volpe_p/rendu/malloc
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Wed Feb 12 12:42:38 2014 volpe
** Last update Sun Feb 16 14:38:31 2014 lardet
*/

#include <unistd.h>
#include "malloc.h"

t_header	*gl_freelist = NULL;
void		*gl_lowlimit = NULL;
int		thread_locked = 0;

static void	*getMoreMem(int size)
{
  int		units;
  void		*address;
  t_header	*tmp;

  units = size;
  if (units < MIN_MALLOC)
    units = MIN_MALLOC;
  address = sbrk(units);
  if (address == (void *)-1)
    return (NULL);
  tmp = address;
  tmp->magic = MALLOC_CHECK;
  tmp->next = NULL;
  if (MIN_MALLOC - size >= SIZESTRUCT)
    {
      tmp->size = size - sizeof(*tmp);
      split_end(tmp);
    }
  else
    tmp->size = size - sizeof(*tmp);
  if (gl_lowlimit == NULL)
    gl_lowlimit = tmp;
  return (tmp);
}

void		*malloc(size_t size)
{
  t_header	*tmp;
  int		total_size;

  if (size <= 0)
    return (NULL);
  lock_thread();
  if ((size % sizeof(int)) != 0)
    size += (sizeof(int) - (size % sizeof(int)));
  if ((tmp = (t_header *)findFreeBlock(size)) == NULL)
    tmp = (t_header *)getMoreMem(size + sizeof(*tmp));
  else
    {
      if (tmp->size - size >= SIZESTRUCT)
	{
	  total_size = tmp->size + sizeof(*tmp);
	  tmp->size = size;
	  split_mid(tmp, total_size);
	}
      deleteFromFreeList(tmp);
    }
  unlock_thread();
  if (tmp == NULL)
    return (NULL);
  return ((void *)((size_t)tmp + sizeof(*tmp)));
}
