/*
** my_strncpy.c for my_strncpy in /home/lardet_e/rendu/Piscine-C-Jour_06
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Oct  7 11:49:26 2013 lardet
** Last update Tue Oct  8 11:45:17 2013 lardet
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	count;
  int	j;

  j = 0;
  count = my_strlen(dest);
  while (src[j] != '\0' && j < n)
    {
      dest[j] = src[j];
      j = j + 1; 
    }
  if (n > count)
    dest[count] = '\0';
  return (dest);
}
