/*
** list.c for list in /home/volpe_p/rendu/malloc
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Wed Feb 12 12:44:08 2014 volpe
** Last update Sun Feb 16 12:21:34 2014 lardet
*/

#include <unistd.h>
#include "malloc.h"

static void	insertInOrder(t_header *last, t_header *tmp, int fusion)
{
  t_header	*current;

  current = last->next;
  while (current)
    {
      if (tmp > current)
	{
	  last = current;
	  current = current->next;
	}
      else
	break;
    }
  last->next = tmp;
  tmp->next = current;
  if (fusion == 1)
    verifyFusion(last);
}

void		deleteFromFreeList(t_header *tmp)
{
  t_header	*save;

  if (tmp == gl_freelist)
    gl_freelist = gl_freelist->next;
  else
    {
      save = gl_freelist;
      while (save->next != tmp)
	save = save->next;
      save->next = tmp->next;
    }
  if (tmp)
    {
      tmp->magic = MALLOC_CHECK;
      tmp->next = NULL;
    }
}

void		addToFreeList(t_header *tmp, int fusion)
{
  t_header	*last;

  tmp->magic = FREE_CHECK;
  tmp->next = NULL;
  last = gl_freelist;
  if (last == NULL)
    gl_freelist = tmp;
  else
    {
      if (tmp < last)
	{
	  tmp->next = gl_freelist;
	  gl_freelist = tmp;
	}
      else
	insertInOrder(last, tmp, fusion);
      verifyFusion(tmp);
    }
}
