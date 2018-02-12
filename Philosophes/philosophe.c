/*
** philosophe.c for philosophe in /home/volpe_p/rendu/Philosophe
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Mon Mar 17 14:11:41 2014 volpe
** Last update Sun Mar 23 12:38:41 2014 lardet
*/

#include "philosophe.h"

int		g_sticks[7];
t_philosophe	g_philos[7];
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void		eating(t_philosophe *philo)
{
  philo->state = 'E';
  philo->states[philo->nb_state] = philo->state;
  philo->nb_state++;
  g_sticks[philo->id] = 1;
  g_sticks[(philo->id + 1) % 7] = 1;
  pthread_mutex_unlock(&g_mutex);
  fprintf(stdout, "\e[1;%smPhilosophe %d : I'm eating now!\e[m\n", philo->color, philo->id);
  sleep(philo->time_to_eat);
  philo->rice -= philo->hunger;
  if (philo->rice < 0)
    philo->rice = 0;
  fprintf(stdout, "\e[1;%smPhilosophe %d : I've finished eating %d rices (rest : %d rice)!\e[m\n", philo->color,  philo->id, philo->hunger, philo->rice);
  pthread_mutex_lock(&g_mutex);
  g_sticks[philo->id] = 0;
  g_sticks[(philo->id + 1) % 7] = 0;
  pthread_mutex_unlock(&g_mutex);
}

void		thinking(t_philosophe *philo)
{
  philo->state = 'T';
  philo->states[philo->nb_state] = philo->state;
  philo->nb_state++;
  g_sticks[philo->id] = 1;
  pthread_mutex_unlock(&g_mutex);
  fprintf(stdout, "\e[1;%smPhilosophe %d : I'm thinking now!\e[m\n", philo->color, philo->id);
  sleep(philo->time_to_think);
  fprintf(stdout, "\e[1;%smPhilosophe %d : I've finished thinking!\e[m\n", philo->color, philo->id);
  while (philo->state != 'E')
    {
      pthread_mutex_lock(&g_mutex);
      if (g_sticks[(philo->id + 1) % 7] == 0)
	eating(philo);
      else
	pthread_mutex_unlock(&g_mutex);
    }
}

void		sleeping(t_philosophe *philo)
{
  pthread_mutex_unlock(&g_mutex);
  if (philo->state == 'R')
    return ;
  philo->state = 'R';
  philo->states[philo->nb_state] = philo->state;
  philo->nb_state++;
  fprintf(stdout, "\e[1;%smPhilosophe %d : I'm going to relax\e[m\n", philo->color, philo->id);
  sleep(philo->time_to_rest);
  fprintf(stdout, "\e[1;%smPhilosophe %d : My energy is full!\e[m\n", philo->color, philo->id);
}

void                *set_brain(void *arg)
{
  t_philosophe	*philo;
  int		left;
  int		right;

  philo = (t_philosophe*)arg;
  fprintf(stdout, "\e[1;%smPhilosophe %d : Came to the table!\e[m\n",philo->color, philo->id);
  while (philo->rice > 0)
    {
      pthread_mutex_lock(&g_mutex);
      left = g_sticks[philo->id];
      right = g_sticks[(philo->id + 1) % 7];
      if (left == 0 && right == 0 && philo->state != 'E')
	eating(philo);
      else if (left == 0 && philo->state != 'T' && philo->state != 'E')
	thinking(philo);
      else
	sleeping(philo);
    }
  fprintf(stdout, "\e[1;%smPhilosophe %d : Left the table!\e[m\n", philo->color, philo->id);
  return (NULL);
}

int         main()
{
  srand(time(NULL));
  init_resources();
  wait_for();
  print_states_history();
  return (0);
}
