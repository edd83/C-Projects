/*
** my_getnbr_base.c for my_getnbr_base in /home/lardet_e/rendu/Piscine-C-Jour_08
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Oct  9 15:22:41 2013 lardet
** Last update Fri Oct 11 15:06:12 2013 lardet
*/

int	my_getnbr_base(char *str, char *base)
{
  int	count_str;
  int	count_base;
  int	i;
  int	j;
  int	result;

  result = 0;
  i = 0;
  count_str = my_strlen(str) - 1;
  count_base = my_strlen(base);
  while (str[i] != '\0')
    {
      j = 0;
      while (base[j] != '\0')
	{
	  if (str[i] == base[j])
	    result = result + (j * my_power_rec(count_base, count_str - i));
	  j = j + 1;
	}
      i = i + 1;
    }
  if (str[0] == '-')
    result = result * -1;
  my_put_nbr(result);
}
