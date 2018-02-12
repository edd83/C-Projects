##
## Makefile for Makefile in /home/volpe_p/rendu/Philosophe
## 
## Made by volpe
## Login   <volpe_p@epitech.net>
## 
## Started on  Mon Mar 17 14:12:45 2014 volpe
## Last update Thu Mar 20 16:51:36 2014 lardet
##

NAME	=	philo

SRC	=	philosophe.c \
		init_utils.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -lpthread

CC	=	gcc

RM	=	rm -f

ECHO	=	echo -e

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@$(ECHO) '\033[0;33m> Compiled\033[0m'

clean	:
	$(RM) $(OBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean	: clean
	$(RM) $(NAME)
	@$(ECHO) '\033[0;33m> Remove executable\033[0m'

re	: fclean all
