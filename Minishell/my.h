/*
** my.h for my.h in /home/lardet_e/rendu/Piscine-C-include
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Thu Oct 10 15:26:24 2013 lardet
** Last update Sun Dec  1 12:49:13 2013 lardet
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
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
int	my_show_wordtab(char **tab);
char	**my_str_to_wordtab_modif(char *str);
char	**my_str_to_wordtab_minishell(char *str);
char	**my_epur_str(char **envp);
void	my_exit(char **av);

#endif
