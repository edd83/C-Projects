/*
** my_strlen.c for my_strlen in /home/lardet_e/rendu/Piscine-C-Jour_07
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Oct  8 09:30:12 2013 lardet
** Last update Sun Nov 24 19:55:13 2013 lardet
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while(str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
