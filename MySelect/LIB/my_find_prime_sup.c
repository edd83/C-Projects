/*
** my_find_prime_sup.c for my_find_prime_sup in /home/lardet_e/rendu/Piscine-C-Jour_07
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Oct  8 21:23:03 2013 lardet
** Last update Wed Oct  9 10:14:51 2013 lardet
*/

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  if (nb == 0 || nb == 1)
    return (0);
  while(i < nb)
    {
      if ((nb % i) == 0)
	return (0);
      i = i + 1;
    }
  return (1);
}

int	my_find_prime_sup(int nb)
{
  int	i;

  while ((i = my_is_prime(nb)) == 0)
    {
      nb = nb + 1;
    }
  return (nb);
}
