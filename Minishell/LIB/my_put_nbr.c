/*
** my_put_nbr.c for my_put_nbr in /home/lardet_e/rendu/Piscine-C-Jour_07
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Oct  8 09:30:52 2013 lardet
** Last update Sun Oct 27 17:10:01 2013 lardet
*/

int	my_put_nbr(int i)
{
  if (i < 0)
    {
      i = i * -1;
      my_putchar('-');
    }
  if (i >= 10)
    {
      my_put_nbr(i / 10);
      my_putchar((i % 10) + 48);
    }
  else
    my_putchar(i + 48);
}
