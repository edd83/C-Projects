##
## Makefile for Makefile in /home/lardet_e/rendu/PSU_2013_malloc/malloc
## 
## Made by lardet
## Login   <lardet_e@epitech.net>
## 
## Started on  Tue Feb 11 20:02:26 2014 lardet
## Last update Sun Feb 16 15:19:01 2014 lardet
##

SRCS	=	malloc.c \
		free.c \
		showmem.c \
		multi_thread.c \
		split.c \
		list.c \
		calloc.c \
		my_printf.c \
		realloc.c \

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

NAME	=	libmy_malloc_$(HOSTTYPE).so

CFLAGS	=	-pthread -W -Wall -Werror -O3

$(NAME): $(OBJS)
	$(CC) -fpic -shared $(SRCS) -o $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJS)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
