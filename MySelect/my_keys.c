/*
** my_keys.c for my_keys in /home/lardet_e/rendu/PSU_2017_my_select
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Nov 23 23:16:03 2013 lardet
** Last update Sun Nov 24 18:44:10 2013 lardet
*/

#include "my.h"

int	my_clear_buffer(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i] != '\0')
    {
      buffer[i] = 0;
      i = i + 1;
    }
  return (0);
}

int	my_call_func(int i, t_list *list)
{
  int	(*func[10])(t_list *);

  func[0] = &my_key_left;
  func[1] = &my_key_right;
  func[2] = &my_key_left;
  func[3] = &my_key_right;
  func[4] = &my_key_valid;
  func[5] = &my_func_exit;
  func[6] = &my_func_select;
  func[7] = &my_func_del;
  func[8] = &my_func_del;
  func[9] = '\0';
  (*func[i])(list);
  return (0);
}

int	my_tab_func(int buffer)
{
  int	str[10];
  int	i;

  str[0] = 4283163;
  str[1] = 4348699;
  str[2] = 4479771;
  str[3] = 4414235;
  str[4] = 10;
  str[5] = 27;
  str[6] = 32;
  str[7] = 127;
  str[8] = 2117294875;
  str[9] = 0;
  i = 0;
  while (i < 9)
    {
      if (str[i] == buffer)
	return (i);
      i = i + 1;
    }
  return (-1);
}

int		my_read(t_list *list)
{
  char		buffer[5];
  t_elem	*elem;
  int		i;

  while(1)
    {
      i = 0;
      my_clear_buffer(buffer);
      read(1, buffer, 4);
      i = my_tab_func(*(int *)buffer);
      if (i != -1)
	my_call_func(i, list);
      my_clear_screen();
      my_show_list(list);
      if (list->out == 1)
	return (0);
    }
}
