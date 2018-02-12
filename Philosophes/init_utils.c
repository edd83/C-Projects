/*
** inits_utils.c for inits utils in /home/volpe_p/rendu/Philosophe
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Mon Mar 17 14:10:48 2014 volpe
** Last update Thu Mar 20 16:59:11 2014 lardet
*/

#include "philosophe.h"

void	init_colors()
{
  g_philos[0].color = "33";
  g_philos[1].color = "31";
  g_philos[2].color = "34";
  g_philos[3].color = "35";
  g_philos[4].color = "36";
  g_philos[5].color = "32";
  g_philos[6].color = "30";
}

void	init_resources()
{
  int	i;

  i = 0;
  init_colors();
  while (i < 7)
    {
      g_philos[i].state = 'R';
      g_philos[i].time_to_think = rand() % 5;
      g_philos[i].time_to_eat = rand() % 5;
      g_philos[i].time_to_rest = rand() % 5;
      g_philos[i].hunger = 10 + rand() % 50;
      g_philos[i].rice = 100;
      g_philos[i].id = i;
      g_philos[i].nb_state = 0;
      g_sticks[i] = 0;
      pthread_create(&(g_philos[i].handler), NULL, set_brain, &g_philos[i]);
      i = i + 1;
    }
}

void	print_states_history()
{
  int	i;

  fprintf(stdout, "\n\nResult : \n\n");
  i = 0;
  while (i < 7)
    {
      g_philos[i].states[g_philos[i].nb_state] = 0;
      printf("\e[1;%smPhilosophe %d : [%s]\e[m\n", g_philos[i].color, i, g_philos[i].states);
      ++i;
    }
}

void	wait_for()
{
  int	i;

  i = 0;
  while (i < 7)
    {
      pthread_join((g_philos[i].handler), NULL);
      i = i + 1;
    }
}
