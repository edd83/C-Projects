/*
** my_revstr.c for my_revstr in /home/lardet_e/rendu/Piscine-C-Jour_06
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Oct  7 15:15:35 2013 lardet
** Last update Tue Oct  8 22:43:01 2013 lardet
*/

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  char	c;

  i = 0;
  j = my_strlen(str) - 1;
  while (j > i)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      j = j - 1;
      i = i + 1;
    }
  return (str);
}
