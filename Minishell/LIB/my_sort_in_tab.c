/*
** my_sort_in_tab.c for my_sort_in_tab in /home/lardet_e/rendu/Piscine-C-Jour_07
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Oct  8 12:56:41 2013 lardet
** Last update Sun Nov 24 19:51:02 2013 lardet
*/

int	my_swap(int *a, int *b)
{
  int	change;

  change = 0;
  change = *a;
  *a = *b;
  *b = change;
}

void	my_sort_int_tab(int *tab, int size)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      if (tab[i] < tab[i - 1])
	{
	  my_swap(&tab[i], &tab[i - 1]);
	  i = i - 2;
	}
      i = i + 1;
    }
}
