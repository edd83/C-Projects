/*
** my_execute_func.c for my_execute_func in /home/lardet_e/rendu/PSU_2017_minishell1
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Nov  7 14:16:10 2013 lardet
** Last update Sun Nov 10 20:42:42 2013 lardet
*/

#include "my.h"

int	my_count_envp(char *envp[])
{
  int	i;

  i = 0;
  while (envp[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

char	*my_epur_list_next(char *final, int i, char *envp[])
{
  int	j;
  char	*dest;

  dest = malloc(sizeof(char *));
  if (dest == NULL)
    return (NULL);
  dest = envp[i];
  j = 0;
  while(dest[j] != '=')
    {
      final[j] = dest[j];
      j = j + 1;
    }
  return (final);
}

int	my_epur_list(char *av, char *envp[])
{
  char	*final;
  int	i;

  i = 0;
  while(envp[i] != '\0')
    {
      final = malloc(sizeof(char *));
      if (final == NULL)
	return (0);
      my_epur_list_next(final, i, envp);
      if (my_strcmp(final, av) == 0)
	return (i);
      i = i + 1;
    }
  return(0);
}

int	execute_setenv(char **av, char *envp[])
{
  int	i;
  char	*dest;

  dest = malloc(sizeof(char *));
  if (dest == NULL)
    return (0);
  i = my_count_envp(envp);
  if (my_epur_list(av[1], envp) != 0)
    {
      i = my_epur_list(av[1], envp);
      dest = av[1];
      my_strcat(dest, "=");
      my_strcat(dest, av[2]);
      envp[i] = dest;
    }
  else
    {
      my_strcat(dest, av[1]);
      my_strcat(dest, "=");
      my_strcat(dest, av[2]);
      envp[i] = dest;
      envp[i + 1] = '\0';
    }
  return (0);
}

int	execute_unsetenv(char *envp[], char **av)
{
  int	i;

  i = 0;
  i = my_epur_list(av[1], envp);
  if (i != 0)
    {
      while (envp[i] != '\0')
	{
	  envp[i] = envp[i + 1];
	  i = i + 1;
	}
    }
  return (0);
}
