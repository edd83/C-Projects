/*
** malloc.h for malloc in /home/lardet_e/rendu/PSU_2013_malloc/malloc
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Feb 11 16:10:58 2014 lardet
** Last update Sun Feb 16 15:21:11 2014 lardet
*/

#ifndef __MALLOC_H__
# define __MALLOC_H__

# define MIN_MALLOC 4096
# define SIZESTRUCT 16
# define MALLOC_CHECK 0x1111
# define FREE_CHECK 0x2222

typedef struct		s_header
{
  unsigned int		magic;
  int			size;
  struct s_header	*next;
}			t_header;

extern t_header	*gl_freelist;
extern void	*gl_lowlimit;
extern int	thread_locked;

int		my_printf(const int fd, char *src, ...);
void		*malloc(size_t size);
void		*calloc(size_t number, size_t size);
void		*realloc(void *ptr, size_t size);
void		*reallocf(void *ptr, int size);
void		free(void *address);
void		*findFreeBlock(int size);
void		addToFreeList(t_header *tmp, int fusion);
void		deleteFromFreeList(t_header *tmp);
int		getListNb(int size);
void		split_mid(t_header *tmp, int total_size);
void		split_end(t_header *tmp);
void		show_alloc_mem(void);
void		verifyFusion(t_header *begin);
t_header	*verifyPtr(void *ptr);
void		lock_thread();
void		unlock_thread();

#endif /* __MALLOC_H__ */
