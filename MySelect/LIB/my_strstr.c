/*
** my_strstr.c for my_strstr in /home/lardet_e/rendu/Piscine-C-Jour_06
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Oct  7 15:24:00 2013 lardet
** Last update Sun Nov  3 15:44:06 2013 lardet
*/

int	my_strstrbis(int *i, int *j, int *k)
{
  if (*j > 0)
    *i = *i - 1;
  *j = 0;
  *k = -1;
}

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = -1;
  while (my_strlen(str) - 1 > i)
    {
      while (str[i] == to_find[j] && i < my_strlen(str))
	{
	  if (k == -1)
	    k = i;
	  j = j + 1;
	  i = i + 1;
	}
      if (j == my_strlen(to_find))
	return (str + k);
      else
	my_strstrbis(&i, &j, &k);
      i = i + 1;
    }
}
