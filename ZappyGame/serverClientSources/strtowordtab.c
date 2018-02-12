/*
** strtowortab.c for strtowordtab in /home/casoni_f/clone/PSU_2013_zappy/serverClientSources
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Mon Jun 30 14:09:31 2014 Fabien Casoni
** Last update Mon Jun 30 14:17:19 2014 Fabien Casoni
*/

#include "server.h"

int		my_strlen(char *s)
{
  int		n;

  n = 0;
  while (s[n] != '\0')
    {
      if (s[n] != ' ' && s[n] != '\t')
        n++;
      else
        return (n);
    }
  return (n);
}

int		count_word(char *s)
{
  int		nb_word;
  int		n;

  nb_word = 0;
  n = 0;
  while (s[n] != '\0')
    {
      if ((n == 0 || s[n - 1] == ' ' || s[n - 1] == '\t')
          && s[n] != ' ' && s[n] != '\t')
        nb_word++;
      n++;
    }
  return (nb_word);
}

char		**strtowordtab(char *s)
{
  int		n;
  int		i;
  int		nb_word;
  int		wd_len;
  char		**tab;

  n = 0;
  i = 0;
  wd_len = 0;
  nb_word = count_word(s);
  tab = malloc(sizeof(*tab) * (nb_word + 1));
  while (n < nb_word)
    {
      while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
        i++;
      wd_len = my_strlen(&s[i]);
      tab[n] = malloc(sizeof(**tab) * (wd_len + 1));
      strncpy(tab[n], &s[i], wd_len);
      tab[n][wd_len] = '\0';
      while (s[i] != '\0' && (s[i] != ' ' && s[i] != '\t'))
        i++;
      n++;
    }
  tab[nb_word] = NULL;
  return (tab);
}
