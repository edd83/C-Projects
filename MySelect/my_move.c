/*
** my_move.c for my_move in /home/lardet_e/rendu/PSU_2017_my_select
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sun Nov 24 14:58:45 2013 lardet
** Last update Sun Nov 24 19:40:53 2013 lardet
*/

#include "my.h"

int		my_key_left(t_list *list)
{
  t_elem	*new_elem;
  int		ok;

  ok = 0;
  new_elem = list->begin;
  while (ok == 0)
    {
      if (new_elem->underline == 1)
	{
	  new_elem->underline = 0;
	  new_elem->prev->underline = 1;
	  ok = 1;
	}
      new_elem = new_elem->next;
    }
  return (0);
}

int	my_key_right(t_list *list)
{
  t_elem	*new_elem;
  int		ok;

  ok = 0;
  new_elem = list->begin;
  while (ok == 0)
    {
      if (new_elem->underline == 1)
	{
	  new_elem->underline = 0;
	  new_elem->next->underline = 1;
	  ok = 1;
	}
      new_elem = new_elem->next;
    }
  return (0);
}

int	my_key_valid(t_list *list)
{
  list->out = 1;
  return (0);
}

int	my_func_exit(t_list *list)
{
  struct termios        t;

  if (tgetent(NULL, "xterm") == -1)
    return (-1);
  if (tcgetattr(0, &t) == -1)
    return (-1);
  t.c_lflag |= (ICANON|ECHO);
  if (tcsetattr(0, TCSANOW, &t) == -1)
    return (-1);
  free(list);
  my_clear_screen();
  _exit(0);
  return (0);
}

int	my_func_select(t_list *list)
{
  t_elem	*new_elem;
  int		ok;

  ok = 0;
  new_elem = list->begin;
  while (ok == 0)
    {
      if (new_elem->underline == 1)
	{
	  if (new_elem->select == 0)
	    {
	      new_elem->select = 1;
	      new_elem->underline = 0;
	      new_elem->next->underline = 1;
	    }
	  else
	    new_elem->select = 0;
	  ok = 1;
	}
      new_elem = new_elem->next;
    }
  return (0);
}
