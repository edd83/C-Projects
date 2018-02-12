/*
** my.h for my.h in /home/lardet_e/rendu/Piscine-C-include
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Oct 10 15:26:24 2013 lardet
** Last update Sun Nov 24 20:00:06 2013 lardet
*/

#ifndef MY_H_
#define MY_H_

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include <term.h>
#include "my_select.h"

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *, int);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
char	*my_strdup(char *src);
char	**my_str_to_wordtab(char *str);
int	my_putnbr_base(int nbr, char *base);
int	my_getnbr_base(char *str, char *base);
int	my_show_wordtab(char **);
void	init(t_list *list);
int	insert_list_void(t_list *list, char *data);
int	insert_elem_list(t_list *list, t_elem *cur, char *data);
int	del_elem_list(t_list *list, t_elem *del_elem);
int	my_show_list(t_list *list);
int	my_underline(t_list *, t_elem *, int, int);
int	my_display(int);
int	my_clear_screen();
int	my_key_left(t_list *);
int	my_key_right(t_list *);
int	my_key_valid(t_list *);
int	my_func_exit(t_list *);
int	my_func_select(t_list *);
int	my_func_del(t_list *);

#endif
