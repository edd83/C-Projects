/*
** my_strlowcase.c for my_strlowcase in /home/lardet_e/rendu/Piscine-C-Jour_07
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Oct  8 22:05:53 2013 lardet
** Last update Sun Nov 24 19:55:59 2013 lardet
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
