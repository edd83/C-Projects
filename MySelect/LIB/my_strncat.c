/*
** my_strncat.c for my_strncat in /home/lardet_e/rendu/Piscine-C-lib/my
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Oct 26 19:14:59 2013 lardet
** Last update Sat Oct 26 19:15:02 2013 lardet
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != 0)
    i = i + 1;
  while (src[j] != 0 && nb > 0)
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
      nb = nb - 1;
    }
  dest[i] = '\0';
  return (dest);
}
