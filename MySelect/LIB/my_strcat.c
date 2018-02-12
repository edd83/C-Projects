/*
** my_strcat.c for my_strcat in /home/lardet_e/rendu/Piscine-C-lib/my
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Oct 26 19:25:39 2013 lardet
** Last update Wed Nov  6 16:41:51 2013 lardet
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != 0)
    i = i + 1;
  while (src[j] != 0)
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
