/*
** my_minishell.c for my_minishell in /home/lardet_e/rendu/PSU_2017_minishell1
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Nov  5 22:49:35 2013 lardet
** Last update Sun Dec  1 13:48:51 2013 lardet
*/

#include "my.h"

int	execute_cd_env(char **av, char *envp[])
{
  int	i;

  i = 0;
  if (my_strcmp(av[0], "env") == 0)
    {
      while (envp[i] != '\0')
	{
	  my_putstr(envp[i]);
	  i = i + 1;
	  my_putchar('\n');
	}
    }
  else if (my_strcmp(av[0], "cd") == 0)
    {
      if (av[1] == NULL)
	{
	  chdir("/home/lardet_e");
	  return (0);
	}
      chdir(av[1]);
    }
  return (0);
}

int	execute_arg(char **av, char *envp[])
{
  char	*dest;
  pid_t	pid;
  int	ret;

  ret = -1;
  dest = malloc(sizeof(char *));
  if (dest == NULL)
    return (0);
  if ((pid = fork()) == -1)
    {
      my_putstr("Erreur");
      return (-1);
    }
  if (pid == 0)
    {
      my_strcat(dest, "/usr/bin/");
      my_strcat(dest, av[0]);
      ret = execve(dest, av, envp);
      return (ret);
    }
  else
    {
      wait(&ret);
      return (ret);
    }
}

char	*my_function_read()
{
  int	i;
  int	lenght;
  char	buffer_read[4096];
  char	*buffer;

  i = 0;
  buffer = malloc(sizeof(char *));
  if (buffer == NULL)
    return (0);
  lenght = read(0, &buffer_read, 4096);
  while ((i < lenght) && (buffer_read[i] != '\n'))
    {
      buffer[i] = buffer_read[i];
      i = i + 1;
    }
  buffer[i] = '\0';
  if (lenght < 1)
    return (0);
  return (buffer);
}

int	my_function_find(char **av, char *envp[], int *j)
{
  if (av[0] == "")
    return (0);
  else
    *j = execute_arg(av, envp);
  if (my_strcmp(av[0], "cd") == 0 || my_strcmp(av[0], "env") == 0)
    execute_cd_env(av, envp);
  else if (my_strcmp(av[0], "setenv") == 0)
    execute_setenv(av, envp);
  else if (my_strcmp(av[0], "unsetenv") == 0)
    execute_unsetenv(envp, av);
  else if (*j == -1)
    {
      my_putstr(av[0]);
      my_putstr(" : command not found");
      my_putchar('\n');
    }
  return (0);
}

int	main(int argc, char **argv, char *envp[])
{
  char	*arguments;
  char	**av;
  int	j;

  j = 0;
  while (1)
    {
      my_putstr("$> ");
      arguments = my_function_read();
      if (arguments)
	{
	  av = my_str_to_wordtab_modif(arguments);
	  if (av[0] == NULL)
	    av[0] = "";
	  if (my_strcmp(av[0], "exit") == 0)
	    return (0);
	  my_function_find(av, envp, &j);
	}
    }
  return (0);
}
