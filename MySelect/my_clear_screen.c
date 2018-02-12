/*
** my_clear_screen.c for my_clear_screen in /home/lardet_e/rendu/PSU_2017_my_select
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Nov 23 23:17:25 2013 lardet
** Last update Sun Nov 24 19:39:10 2013 lardet
*/

#include "my.h"

int	my_display(int i)
{
  my_putchar(i);
  return (0);
}

int	my_clear_screen()
{
  tputs(tgetstr("cl", NULL), 0, my_display);
  return (0);
}

int		my_func_del(t_list *list)
{
  t_elem	*new_elem;
  int		ok;

  ok = 0;
  new_elem = list->begin;
  while (ok == 0)
    {
      if (new_elem->underline == 1)
        {
          if (new_elem == list->end && new_elem == list->begin)
            my_func_exit(list);
          else
            del_elem_list(list, new_elem);
          ok = 1;
        }
      new_elem = new_elem->next;
    }
  return (0);
}
