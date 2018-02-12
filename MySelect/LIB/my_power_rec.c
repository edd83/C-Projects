/*
** my_power_rec.c for my_power_rec in /home/lardet_e/rendu/Piscine-C-Jour_05
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Oct  4 18:13:55 2013 lardet
** Last update Sun Nov 24 19:47:53 2013 lardet
*/

int	my_power_rec(int i, int power)
{
  if (power > 1)
    i = i * my_power_rec(i, power - 1);
  return (i);
}
