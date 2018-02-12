/*
** convert_base.c for convert_base in /home/lardet_e/rendu/Piscine-C-Jour_08/ex_02
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Oct  9 16:13:45 2013 lardet
** Last update Thu Oct 10 23:31:45 2013 lardet
*/

#include <stdlib.h>

char	*new_strdup(char *src)
{
  int	lenght;
  int	i;
  char	*new;

  lenght = my_strlen(src);
  new = malloc(lenght * sizeof(*new));
  i = 0;
  while (i < lenght)
    {
      new[i] = src[i];
      i = i + 1;
    }
  new[i] = 0;
  return (new);
}

void	my_getchar_base(int nbr, char *base, char *final)
{
  int	len;
  int	increm;

  len = my_strlen(base);
  if (nbr < 0)
    {
      final[0] = '-';
      nbr = nbr * -1;
    }
  if (nbr >= len)
    {
      my_getchar_base(nbr / len, base, final);
      my_getchar_base(nbr % len, base, final);
    }
  else
    final[my_strlen(final)] = base[nbr];
}

int	my_getn_base(char *str, char *base)
{
  int	y;
  int	i;
  int	ceiling;
  int	ceilingbis;
  int	compt;

  ceiling = my_strlen(base);
  ceilingbis = my_strlen(str);
  y = 0;
  compt = 0;
  while (str[y] != 0)
    {
      i = 0;
      while (base[i] != 0)
	{
	  if (str[y] == base[i])
	    compt = compt + (i * my_power_rec(ceiling, ceilingbis - y - 1));
	  i = i + 1;
	}
      y = y + 1;
    }
  return (compt);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	decimal;
  char	final[4096];
  char	*fin;

  fin = &final[0];
  decimal = my_getn_base(nbr, base_from);
  my_getchar_base(decimal, base_to, fin);
  return (new_strdup(fin));
}
