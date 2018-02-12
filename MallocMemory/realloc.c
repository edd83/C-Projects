/*
** realloc.c for realloc in /home/volpe_p/rendu/malloc
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Wed Feb 12 12:42:49 2014 volpe
** Last update Sun Feb 16 15:17:58 2014 lardet
*/

#include <string.h>
#include <unistd.h>
#include "malloc.h"

t_header	*verifyPtr(void *ptr)
{
  t_header	*tmp;

  if (ptr == NULL)
    return (NULL);
  lock_thread();
  if (gl_lowlimit == NULL)
    {
      my_printf(2, "[malloc] Error: No first malloc found\n");
      unlock_thread();
      return (NULL);
    }
  if (ptr < gl_lowlimit)
    {
      my_printf(2, "[malloc] Error: Address is before the low limit.\n");
      unlock_thread();
      return (NULL);
    }
  tmp = (t_header *)((size_t)ptr - sizeof(*tmp));
  unlock_thread();
  return (tmp);
}

void		*realloc(void *ptr, size_t size)
{
  t_header	*tmp;
  void		*new;
  unsigned int		bak_size;

  if (ptr == NULL)
    return (malloc(size));
  if ((tmp = verifyPtr(ptr)) == NULL)
    return (NULL);
  if ((size_t)tmp->size == size)
    return (ptr);
  lock_thread();
  bak_size = tmp->size;
  addToFreeList(tmp, 0);
  unlock_thread();
  new = malloc(size);
  lock_thread();
  if (ptr != new)
    {
      if (size > bak_size)
	memcpy(new, ptr, bak_size);
      else
	memcpy(new, ptr, size);
    }
  unlock_thread();
  return (new);
}

void		*reallocf(void *ptr, int size)
{
  void		*addr;
  t_header	*tmp;

  addr = realloc(ptr, size);
  if (addr == NULL)
    {
      tmp = verifyPtr(ptr);
      if (tmp == NULL)
	return (NULL);
      if (tmp->magic == MALLOC_CHECK)
	free((void *)((size_t)tmp + sizeof(*tmp)));
    }
  return (addr);
}
