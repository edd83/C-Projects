##
## Makefile for Makefile in /home/lardet_e/rendu/Piscine-C-lib/my
## 
## Made by lardet
## Login   <lardet_e@epitech.net>
## 
## Started on  Mon Oct 21 09:43:47 2013 lardet
## Last update Sun Nov 24 20:00:41 2013 lardet
##

SRC	=	my_putchar.c		\
		my_find_prime_sup.c	\
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_power_rec.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_showmem.c		\
		my_showstr.c		\
		my_sort_in_tab.c	\
		my_square_root.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlcat.c		\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_strupcase.c		\
		my_strdup.c		\
		convert_base.c		\
		my_putnbr_base.c	\
		my_swap.c		

## my_get_nbrbase
## my_show_wordtab

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
