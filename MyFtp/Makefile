##
## Makefile for Makefile in /home/lardet_e/rendu/PSU_2013_myftp
## 
## Made by lardet
## Login   <lardet_e@epitech.net>
## 
## Started on  Sun Apr 13 23:04:51 2014 lardet
## Last update Sun Apr 13 23:23:09 2014 lardet
##

CC		=	gcc
RM		=	rm -f
CFLAGS		+=	-W -Wall -g

####################################################
## SERVER
####################################################

SRV_NAME	=	serveur
SRV_OBJS	=	$(SRV_SRCS:.c=.o)
SRV_DIR		=	./server/

SRV_SRCS	=	$(SRV_DIR)main.c		\
			$(SRV_DIR)my_error.c		\
			$(SRV_DIR)init_server.c		\
			$(SRV_DIR)xfunction.c		\
			$(SRV_DIR)func_other.c		\
			$(SRV_DIR)accept_connection.c	\

####################################################
## CLIENT
####################################################

CLT_NAME	=	client
CLT_OBJS	=	$(CLT_SRCS:.c=.o)
CLT_DIR		=	./client_d/

CLT_SRCS	=	$(CLT_DIR)main.c		\
			$(CLT_DIR)my_error.c		\
			$(CLT_DIR)init_client.c		\
			$(CLT_DIR)xfunction.c		\
			$(CLT_DIR)func_other.c		\
			$(CLT_DIR)puts_color.c		\
			$(CLT_DIR)get_next_line.c	\

####################################################
## RULES
####################################################

all		:	$(SRV_NAME) $(CLT_NAME)

$(SRV_NAME)	:	$(SRV_OBJS)
		$(CC) -o $(SRV_NAME) $(SRV_OBJS)

$(CLT_NAME)	:	$(CLT_OBJS)
		$(CC) -o $(CLT_NAME) $(CLT_OBJS)

clean		:
		$(RM) $(SRV_OBJS)
		$(RM) $(CLT_OBJS)

fclean		:	clean
		$(RM) $(SRV_NAME)
		$(RM) $(CLT_NAME)

re		:	fclean all
