/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/lardet_e/rendu/PSU_2013_minishell2/LIB
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sat Nov 30 16:38:30 2013 lardet
** Last update Sun Dec  1 13:37:10 2013 lardet
*/

#include <stdlib.h>

int	is_alpha_m(char c)
{
  if (c >= 32 && c <= 57)
    return (1);
  else if (c >= 59 && c <= 126)
    return (1);
  return (0);
}

char	*my_loop_mini(int *j, int i, char *str, char *pointeur)
{
  int	k;
  int	h;

  k = 0;
  while (is_alpha_m(str[*j]) == 0)
    *j = *j + 1;
  h = *j;
  while (is_alpha_m(str[h]) == 1)
    {
      k = k + 1;
      h = h + 1;
    }
  pointeur = malloc(sizeof(char) * k);
  k = 0;
  while (is_alpha_m(str[*j]) == 1)
    {
      pointeur[k] = str[*j];
      *j = *j + 1;
      k = k + 1;
    }
  pointeur[k] = 0;
  return (pointeur);
}

char	**my_str_to_wordtab_minishell(char *str)
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
      j = (is_alpha_m(str[i]) == 0 && is_alpha_m(str[i + 1]) == 1) ? j + 1 : j;
      i = i + 1;
    }
  save_j = (is_alpha_m(str[0]) == 1) ? j + 1 : j;
  ptr2 = malloc(sizeof(char *) * save_j);
  i = 0;
  j = 0;
  while (i < save_j)
    {
      pointeur = my_loop_mini(&j, i, str, pointeur);
      ptr2[i] = pointeur;
      i = i + 1;
    }
  ptr2[i] = 0;
  return (ptr2);
}
