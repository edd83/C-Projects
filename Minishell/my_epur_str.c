/*
** my_epur_str.c for my_epur_str in /home/lardet_e/rendu/PSU_2017_minishell1
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Nov  8 22:04:49 2013 lardet
** Last update Sun Dec  1 22:28:26 2013 lardet
*/

#include "my.h"
#include <signal.h>

void	my_exit(char **av)
{
  kill(0, SIGINT);
}
