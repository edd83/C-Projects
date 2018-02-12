/*
** my_swap.c for my_swap in /home/lardet_e/rendu/Piscine-C-Jour_04
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Oct  3 10:07:02 2013 lardet
** Last update Sun Nov 24 19:59:45 2013 lardet
*/

int	my_swap(int *a, int *b)
{
  int	change;

  change = *a;
  *a = *b;
  *b = change;
}
