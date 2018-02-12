/*
** thread_safe.c for thread safe in /home/volpe_p/rendu/malloc
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Wed Feb 12 12:43:46 2014 volpe
** Last update Sun Feb 16 14:37:57 2014 lardet
*/

#include <unistd.h>
#include <pthread.h>
#include "malloc.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void	lock_thread()
{
  pthread_mutex_lock(&mutex);
}

void	unlock_thread()
{
  pthread_mutex_unlock(&mutex);
}
