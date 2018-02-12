/*
** philosophe.h for philosophe in /home/volpe_p/rendu/Philosophe
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Mon Mar 17 14:12:22 2014 volpe
** Last update Sun Mar 23 12:37:56 2014 lardet
*/

#ifndef PHILOSHOPE_H_
# define PHILOSHOPE_H_

#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct      s_philosophe
{
  int		id;
  pthread_t	handler;
  char		state;
  int		time_to_think;
  int		time_to_eat;
  int		time_to_rest;
  int		rice;
  int		hunger;
  char		*color;
  char		states[512];
  int		nb_state;
}                   t_philosophe;

extern int			g_sticks[7];
extern pthread_mutex_t		g_mutex;
extern t_philosophe		g_philos[7];

void		init_resources(void);
void		wait_for(void);
void		*set_brain(void *);
void		sleeping(t_philosophe *);
void		thinking(t_philosophe *);
void		eating(t_philosophe *);
void		init_colors(void);
void		init_resources(void);
void		print_states_history(void);

#endif /* !PHILOSHOPE_H_ */
