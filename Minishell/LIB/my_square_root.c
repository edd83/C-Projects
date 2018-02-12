/*
** my_square_root.c for my_square_root in /home/lardet_e/rendu/Piscine-C-Jour_07
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Oct  8 17:58:04 2013 lardet
** Last update Tue Oct  8 21:01:13 2013 lardet
*/

int	my_square_root(int nb)
{
  int	i;
  int	j;

  while (i < nb)
    {
      if ((i * i) == nb)
	return (i);
      i = i + 1;
    }
  return (0);
}
