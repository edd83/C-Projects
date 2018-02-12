##
## Makefile for Makefile in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources/SFML
## 
## Made by volpe
## Login   <volpe_p@epitech.net>
## 
## Started on  Mon Jun 23 17:36:29 2014 volpe
## Last update Sun Jul 13 22:08:12 2014 volpe
##

CC	= 	g++

RM	= 	rm -rf

SRCS_PATH =	./srcs/

INCLUDES  = 	-I SFML/lib/				\
		-I SFML/include/

LIBRARY	+= 	-lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio
LIBRARY	+= 	-lGLEW -ljpeg

CXXFLAGS =	-Werror -W -Wextra

NAME 	= 	GraphClient

SRCS	= 	$(SRCS_PATH)main.cpp			\
		$(SRCS_PATH)Window.cpp			\
		$(SRCS_PATH)Map.cpp			\
		$(SRCS_PATH)Square.cpp			\
		$(SRCS_PATH)GraphClient.cpp		\
		$(SRCS_PATH)Parsing.cpp			\
		$(SRCS_PATH)Trentonian.cpp		\
		$(SRCS_PATH)Team.cpp			\
		$(SRCS_PATH)Egg.cpp			\
		$(SRCS_PATH)ParserException.cpp		\
		$(SRCS_PATH)Inventory.cpp		\
		$(SRCS_PATH)Hud.cpp			\
		$(SRCS_PATH)Object.cpp			\
		$(SRCS_PATH)AObject.cpp			\
		$(SRCS_PATH)Client.cpp			\
		$(SRCS_PATH)Socket.cpp			\
		$(SRCS_PATH)Select.cpp			\
		$(SRCS_PATH)Error.cpp			\
		$(SRCS_PATH)MyException.cpp		\
		$(SRCS_PATH)Containers.cpp		\
		$(SRCS_PATH)Random.cpp			\
		$(SRCS_PATH)Time.cpp			\
		$(SRCS_PATH)NbMath.cpp			

OBJS	= 	$(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS) $(LIBRARY)

all : $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	 $(RM) $(NAME)

re: fclean all
