/*
** my_strcmp.c for my_strcmp in /home/lardet_e/rendu/Piscine-C-Jour_07
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Oct  8 22:19:50 2013 lardet
** Last update Sun Nov 24 19:52:14 2013 lardet
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    i = i + 1;
  return (s1[i] - s2[i]);
}
