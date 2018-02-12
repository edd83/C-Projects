/*
** my_show_wordtab.c for my_show_wordtab in /home/lardet_e/rendu/Piscine-C-Jour_09/ex_03
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Oct 11 14:26:49 2013 lardet
** Last update Sun Nov 24 19:50:26 2013 lardet
*/

#include <stdlib.h>

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}
