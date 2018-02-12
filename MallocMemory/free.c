/*
** free.c for free.c in /home/volpe_p/rendu/malloc
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Wed Feb 12 12:42:14 2014 volpe
** Last update Sun Feb 16 15:16:37 2014 lardet
*/

#include <unistd.h>
#include "malloc.h"

void		verifyFusion(t_header *begin)
{
  t_header	*block;

  if (begin && begin->next)
    {
      block = (t_header *)((size_t)begin + begin->size + sizeof(*begin));
      if (block->magic == FREE_CHECK)
	{
	  begin->size = begin->size + block->size + sizeof(*block);
	  begin->next = block->next;
	}
    }
}

void		*findFreeBlock(int size)
{
  t_header	*begin;
  t_header	*tmp;
  unsigned int	min_size;

  tmp = NULL;
  min_size = -1;
  begin = gl_freelist;
  while (begin)
    {
      if ((unsigned int)begin->size < min_size && begin->size >= size)
	{
	  tmp = begin;
	  min_size = begin->size;
	}
      begin = begin->next;
    }
  return (tmp);
}

void		free(void *addr)
{
  t_header	*tmp;

  tmp = verifyPtr(addr);
  if (tmp == NULL)
    return ;
  lock_thread();
  if (tmp->magic == FREE_CHECK)
    my_printf(2, "[malloc] Error: The block is already free.\n");
  if (tmp->magic == MALLOC_CHECK)
    addToFreeList(tmp, 1);
  else
    my_printf(2, "[malloc] Error: Junk Pointer.\n");
  unlock_thread();
}
