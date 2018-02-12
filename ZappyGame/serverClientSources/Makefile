##
## Makefile for Makefile in /home/lardet_e/rendu/PSU_2013_myftp
## 
## Made by lardet
## Login   <lardet_e@epitech.net>
## 
## Started on  Sun Apr 13 23:04:51 2014 lardet
## Last update Sat Jul 19 10:34:54 2014 lardet
##

CC		=	gcc
RM		=	rm -f
CFLAGS		+=	-W -Wall -Wextra -Werror

####################################################
## SERVER
####################################################

NAME_SERV	=	serveur
OBJS_SERV	=	$(SRCS_SERV:.c=.o)

SRCS_SERV	=	server.c		\
			func_serv.c		\
			parser.c		\
			functions_ptr.c		\
			functions2_ptr.c	\
			func_team.c		\
			func_player.c		\
			others_events.c		\
			movement.c		\
			manip.c			\
			create.c		\
			content_func.c		\
			content_func2.c		\
			player_actions.c	\
			erase.c			\
			message.c		\
			expulse.c		\
			execute_command.c	\
			execute_actions_1.c	\
			execute_actions_2.c	\
			strtowordtab.c		\
			see_func.c		\
			timer.c			\
			reorder_timer.c		\
			check_timer.c		\
			manage_life.c		\
			manage_life_2.c		\
			life.c			\
			erase_player.c		\
			wait_client.c		\
			wait_client2.c		\
			incant2.c		\
			incant.c		\
			requirements.c		\
			egg.c			\
			broadcast.c		\
			broadcast_func.c	\
			broadcast_func2.c

####################################################
## RULES
####################################################

all		:	$(NAME_SERV)

$(NAME_SERV)	:	$(OBJS_SERV)
		$(CC) $(OBJS_SERV) -o $(NAME_SERV)

clean		:
		$(RM) $(OBJS_SERV)

fclean		:	clean
		$(RM) $(NAME_SERV)

re		:	fclean all
