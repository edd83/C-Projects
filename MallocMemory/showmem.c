/*
** showmem.c for showmem in /home/volpe_p/rendu/malloc
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Wed Feb 12 12:43:15 2014 volpe
** Last update Sun Feb 16 15:25:02 2014 lardet
*/

#include <unistd.h>
#include "malloc.h"

void		show_alloc_mem()
{
  void		*addr;
  void		*end;
  t_header	*tmp;
  int		offset;
  int		size;

  addr = gl_lowlimit;
  end = sbrk(0);
  my_printf(2, "break : 0x%x\n", end);
  if (addr == NULL)
    return ;
  while ((size_t)addr <= (size_t)end)
    {
      tmp = addr;
      offset = sizeof(*tmp) + tmp->size + (size_t)tmp;
      size = tmp->size + sizeof(*tmp);
      if (tmp->magic == MALLOC_CHECK)
	my_printf(2, "0x%x - 0x%x : %d octets\n", tmp, offset, size);
      addr = (void *)((size_t)addr + tmp->size + sizeof(*tmp));
    }
}
