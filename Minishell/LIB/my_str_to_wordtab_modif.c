/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/lardet_e/rendu/PSU_2013_minishell2/LIB
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Nov 30 16:38:30 2013 lardet
** Last update Sat Nov 30 17:10:00 2013 lardet
*/

#include <stdlib.h>

int	is_alpha_n(char c)
{
  if (c >= 33 && c <= 58)
    return (1);
  else if (c == 61)
    return (1);
  else if (c >= 63 && c <= 123)
    return (1);
  else if (c >= 125 && c <= 127)
    return (1);
  return (0);
}

char	*my_loop_n(int *j, int i, char *str, char *pointeur)
{
  int	k;
  int	h;

  k = 0;
  while (is_alpha_n(str[*j]) == 0)
    *j = *j + 1;
  h = *j;
  while (is_alpha_n(str[h]) == 1)
    {
      k = k + 1;
      h = h + 1;
    }
  pointeur = malloc(sizeof(char) * k);
  k = 0;
  while (is_alpha_n(str[*j]) == 1)
    {
      pointeur[k] = str[*j];
      *j = *j + 1;
      k = k + 1;
    }
  pointeur[k] = 0;
  return (pointeur);
}

char	**my_str_to_wordtab_modif(char *str)
{
  char	**ptr2;
  int	i;
  int	j;
  int	save_j;
  char	*pointeur;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      j = (is_alpha_n(str[i]) == 0 && is_alpha_n(str[i + 1]) == 1) ? j + 1 : j;
      i = i + 1;
    }
  save_j = (is_alpha_n(str[0]) == 1) ? j + 1 : j;
  ptr2 = malloc(sizeof(char *) * save_j);
  i = 0;
  j = 0;
  while (i < save_j)
    {
      pointeur = my_loop_n(&j, i, str, pointeur);
      ptr2[i] = pointeur;
      i = i + 1;
    }
  ptr2[i] = 0;
  return (ptr2);
}
