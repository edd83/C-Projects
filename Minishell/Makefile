##
## Makefile for Makefile in /home/lardet_e/rendu/my_ls
## 
## Made by lardet
## Login   <lardet_e@epitech.net>
## 
## Started on  Tue Oct 29 17:56:34 2013 lardet
## Last update Sat Nov 30 16:30:19 2013 lardet
##

NAME=	mysh

SRC=	my_minishell2.c		\
	my_epur_str.c		\
	my_execute_func.c

OBJ=	$(SRC:.c=.o)

LIB=	-lmy -LLIB/

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
