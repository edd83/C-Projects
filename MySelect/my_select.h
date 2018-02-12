/*
** my_select.h for my_select in /home/lardet_e/rendu/PSU_2017_my_select
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Nov 23 23:20:53 2013 lardet
** Last update Sun Nov 24 18:19:58 2013 lardet
*/

#ifndef MY_SELECT
# define MY_SELECT

typedef struct element_list {
  char	*data;
  int	underline;
  int	select;
  struct element_list *next;
  struct element_list *prev;
} t_elem;

typedef struct list_rep {
  t_elem	*begin;
  t_elem	*end;
  int		size;
  int		out;
}t_list;

#endif
