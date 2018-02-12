/*
** my_list.c for my_list in /home/lardet_e/rendu/PSU_2017_my_select
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Nov 23 23:16:28 2013 lardet
** Last update Sun Nov 24 18:20:23 2013 lardet
*/

#include "my.h"

void	init(t_list *list)
{
  list->begin = NULL;
  list->end = NULL;
  list->size = 0;
  list->out = 0;
}

int		insert_list_void(t_list *list, char *data)
{
  t_elem	*new_elem;

  new_elem = malloc(sizeof(t_elem *));
  if (new_elem == NULL)
    return (-1);
  if ((new_elem->data = (char *)malloc(50 * sizeof(char))) == NULL)
    return (-1);
  my_strcpy(new_elem->data, data);
  new_elem->underline = 1;
  new_elem->select = 0;
  new_elem->prev = new_elem;
  new_elem->next = new_elem;
  list->begin = new_elem;
  list->end = new_elem;
  list->size = list->size + 1;
  return (0);
}

int		insert_elem_list(t_list *list, t_elem *cur, char *data)
{
  t_elem	*new_elem;

  new_elem = malloc(sizeof(t_elem *));
  if (new_elem == NULL)
    return (-1);
  if ((new_elem->data = (char *)malloc(50 * sizeof(char))) == NULL)
    return (-1);
  my_strcpy(new_elem->data, data);
  new_elem->underline = 0;
  new_elem->select = 0;
  new_elem->next = cur->next;
  cur->next = new_elem;
  new_elem->prev = cur;
  if (new_elem->next == list->begin)
    {
      list->end = new_elem;
      list->begin->prev = new_elem;
    }
  list->size = list->size + 1;
  return (0);
}

int		del_elem_list(t_list *list, t_elem *del_elem)
{
  int	i;
  t_elem	*elem;

  if (list->size < 2)
    return (-1);
  del_elem->prev->underline = 1;
  del_elem->prev->next = del_elem->next;
  del_elem->next->prev = del_elem->prev;
  list->size = list->size - 1;
  if (del_elem == list->end)
    list->end = del_elem->prev;
  if (del_elem == list->begin)
    list->begin = list->begin->next;
  return (0);
}

int	my_show_list(t_list *list)
{
  t_elem	*elem;
  int	i;

  elem = list->begin;
  i = 0;
  while (i < list->size)
    {
      if (elem->underline == 1 || elem->select == 1)
	my_underline(list, elem, elem->underline, elem->select);
      else
	my_putstr(elem->data);
      elem = elem->next;
      i = i + 1;
      my_putchar('\t');
    }
  return (0);
}
