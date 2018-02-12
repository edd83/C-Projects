##
## Makefile for Makefile in /home/lardet_e/rendu/my_ls
## 
## Made by lardet
## Login   <lardet_e@epitech.net>
## 
## Started on  Tue Oct 29 17:56:34 2013 lardet
## Last update Sun Nov 24 15:26:36 2013 lardet
##

NAME=	my_select

SRC=	my_select.c		\
	my_list.c		\
	my_keys.c		\
	my_move.c		\
	my_clear_screen.c

OBJ=	$(SRC:.c=.o)

LIB=	-lmy -LLIB/ -lncurses

CFLAGS=	-I./

all:	$(NAME)

$(NAME): $(OBJ)
	make -C LIB/
	cc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
