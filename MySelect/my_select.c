/*
** my_select.c for my_select in /home/lardet_e/rendu/PSU_2017_my_select
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Nov 23 23:15:42 2013 lardet
** Last update Sun Nov 24 20:03:24 2013 lardet
*/

#include "my.h"

t_list		*my_create_list(int ac, char **av)
{
  t_list	*list;
  t_elem	*elem;
  int		i;

  i = 2;
  list = malloc(sizeof(t_list *));
  if (list == NULL)
    return (NULL);
  init(list);
  if (ac != 0 && ac != 1)
    {
      ac = ac -2;
      insert_list_void(list, av[1]);
      elem = list->begin;
      while (ac != 0)
	{
	  insert_elem_list(list, elem, av[i]);
	  elem = elem->next;
	  ac = ac - 1;
	  i = i + 1;
	}
      my_show_list(list);
    }
  return (list);
}

int	my_underline(t_list *list, t_elem *elem, int underline, int select)
{
  if (underline == 1)
    tputs(tgetstr("us", NULL), 0, my_display);
  if (select == 1)
    tputs(tgetstr("so", NULL), 0, my_display);
  my_putstr(elem->data);
  tputs(tgetstr("me", NULL), 0, my_display);
  return (0);
}

int	my_select(t_list *list)
{
  struct termios	t;

  if (tgetent(NULL, "xterm") == -1)
    return (-1);
  if (tcgetattr(0, &t) == -1)
    return (-1);
  t.c_lflag &= ~(ICANON|ECHO);
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &t) == -1)
    return (-1);
  my_clear_screen();
  my_show_list(list);
  my_read(list);
  t.c_lflag |= (ICANON|ECHO);
  if (tcsetattr(0, TCSANOW, &t) == -1)
    return (-1);
}

char		*my_return(t_list *list, char *str)
{
  t_elem	*elem;
  int		i;

  i = 0;
  elem = list->begin;
  str = malloc(sizeof(char) * 4096);
  if (str == NULL)
    return ("-1");
  while (list->size > i)
    {
      if (elem->select == 1)
	{
	  my_strcat(str, elem->data);
	  my_strcat(str, " ");
	}
      elem = elem->next;
      i = i + 1;
    }
  my_strcat(str, "\0");
  my_putchar('\n');
  return (str);
}

char		*main(int ac, char **av)
{
  t_list	*list;
  char		*str;
  int		i;

  i = 0;
  if (ac == 1)
    {
      my_putstr("Not enough arguments: ./my_select <arg1> ...\n");
      return ("-1");
    }
  while (i < ac)
    {
      if (my_strlen(av[i]) > 55)
	{
	  my_putstr("Invalid lenght arguments");
	  return ("0");
	}
      i = i + 1;
    }
  list = NULL;
  list = my_create_list(ac, av);
  my_select(list);
  str = my_return(list, str);
  free(list);
  return (str);
}
