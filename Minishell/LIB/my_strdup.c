/*
** my_strdup.c for my_strdup in /home/lardet_e/rendu/Piscine-C-Jour_08
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Oct  9 11:22:56 2013 lardet
** Last update Wed Nov  6 20:29:50 2013 lardet
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*dest;
  int	i;

  i = my_strlen(src);
  dest = malloc(i);
  my_strcpy(dest, src);
  return (dest);
}
