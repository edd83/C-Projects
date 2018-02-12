##
## Makefile for zappy_ai in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources
## 
## Made by ovoyan_s
## Login   <ovoyan_s@epitech.net>
## 
## Started on  Mon May  5 16:20:28 2014 ovoyan_s
## Last update Sun Jul 20 18:29:00 2014 ovoyan_s
##

MY_CPP_LIBRARIES	=	my_cpp_libraries

SOURCES_PATH		=	sources

HEADERS_PATH		=	headers

CLIENT_PART		=	clientPart

SRC			=	$(CLIENT_PART)/Client.cpp		\
				$(CLIENT_PART)/Error.cpp		\
				$(CLIENT_PART)/Select.cpp		\
				$(CLIENT_PART)/Socket.cpp		\
				$(MY_CPP_LIBRARIES)/Containers.cpp 	\
				$(MY_CPP_LIBRARIES)/Math.cpp 		\
				$(MY_CPP_LIBRARIES)/MyException.cpp 	\
				$(MY_CPP_LIBRARIES)/Random.cpp 		\
				$(MY_CPP_LIBRARIES)/Time.cpp 		\
				$(SOURCES_PATH)/Communication.cpp 	\
				$(SOURCES_PATH)/ExternInteractions.cpp	\
				$(SOURCES_PATH)/InventoryActions.cpp	\
				$(SOURCES_PATH)/Inventory.cpp 		\
				$(SOURCES_PATH)/main.cpp 		\
				$(SOURCES_PATH)/MoveActions.cpp		\
				$(SOURCES_PATH)/NbMath.cpp		\
				$(SOURCES_PATH)/ParsingMessage.cpp	\
				$(SOURCES_PATH)/Ressource.cpp 		\
				$(SOURCES_PATH)/Trentonian.cpp		\
				$(SOURCES_PATH)/TrentonianActions.cpp

OBJ			=	$(SRC:.cpp=.o)

RM			=	rm -rf

CC			=	g++

NAME			=	clientAI

INCLUDES		=	-I$(HEADERS_PATH) \
				-I$(MY_CPP_LIBRARIES)

CXXFLAGS		=	-W -Wall -Werror -Wextra $(INCLUDES)

all:				$(NAME)

$(NAME):			$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(INCLUDES)

clean:	
				$(RM) $(OBJ)

fclean:				clean
				$(RM) $(NAME)

re:				fclean all
