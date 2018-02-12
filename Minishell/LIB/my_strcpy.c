/*
** my_strcpy.c for my_strcpy in /home/lardet_e/rendu/Piscine-C-Jour_06
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Oct  7 09:07:29 2013 lardet
** Last update Fri Oct 11 15:18:28 2013 lardet
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return(dest);
}
