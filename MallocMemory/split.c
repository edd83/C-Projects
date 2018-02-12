/*
** split.c for split in /home/volpe_p/rendu/malloc
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Wed Feb 12 12:43:27 2014 volpe
** Last update Sun Feb 16 15:24:49 2014 lardet
*/

#include <unistd.h>
#include "malloc.h"

void		split_mid(t_header *tmp, int total_size)
{
  t_header	*newBlock;
  int		offset;

  offset = sizeof(*tmp) + tmp->size;
  newBlock = (t_header *)((size_t)tmp + offset);
  newBlock->magic = FREE_CHECK;
  newBlock->size = total_size - offset - sizeof(*newBlock);
  newBlock->next = tmp->next;
  tmp->next = newBlock;
  verifyFusion(newBlock);
}

void		split_end(t_header *tmp)
{
  t_header	*newBlock;
  int		offset;

  offset = sizeof(*tmp) + tmp->size;
  newBlock = (t_header *)((size_t)tmp + offset);
  newBlock->size = MIN_MALLOC - offset - sizeof(*newBlock);
  addToFreeList(newBlock, 0);
}
