/*
** my_getnbr.c for my_getnbr in /home/lardet_e/rendu/Piscine-C-Jour_07
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Oct  8 10:01:16 2013 lardet
** Last update Fri Oct 11 15:06:30 2013 lardet
*/

int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

int	is_neg(char *str)
{
  int	compteur;
  int	i;

  i = 0;
  compteur = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
	compteur = compteur + 1;
      i = i + 1;
    }
  if ((compteur % 2) == 1)
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (is_num(str[i]) == 0)
    i = i + 1;
  while (is_num(str[i]) == 1)
    {
      nb = (nb * 10) + (str[i] - 48);
      i = i + 1;
    }
  if (is_neg(str) == 1)
      nb = nb * -1;
  return (nb);
}
