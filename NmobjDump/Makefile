##
## Makefile for Makefile in /home/lardet_e/TP/nm-objdump/objdump
## 
## Made by lardet
## Login   <lardet_e@epitech.net>
## 
## Started on  Wed Mar 12 23:30:49 2014 lardet
## Last update Sat Mar 15 11:24:45 2014 lardet
##

CFLAGS		+=	-W -Wall -Werror
RM		=	rm -rf
CC		=	gcc

#####################################################################
# NM
#####################################################################
NM		=	my_nm

NM_SRCS		=	./nm/nm.c		\
			./nm/xfunc.c		\
			./nm/elf64_format.c	\
			./nm/print_sym64.c

NM_OBJS		=	$(NM_SRCS:.c=.o)

#####################################################################
# OBJDUMP -f -s
#####################################################################
OBJDUMP		=	my_objdump
DIR_OBJDP	=	./objdump
OBJDP_OBJS	=	$(OBJDUMP_SRCS:.c=.o)

OBJDUMP_SRCS	=	$(DIR_OBJDP)/objdump.c		\
			$(DIR_OBJDP)/xfunc.c		\
			$(DIR_OBJDP)/objdp32_format.c	\
			$(DIR_OBJDP)/printf_flags.c	\
			$(DIR_OBJDP)/objdp64_format.c	\
			$(DIR_OBJDP)/check_file.c

#####################################################################
# RULES
#####################################################################

all		:	$(NM) $(OBJDUMP)

$(NM)		:	$(NM_OBJS)
		$(CC) -o $(NM) $(NM_OBJS) $(CFLAGS)

$(OBJDUMP)	:	$(OBJDP_OBJS)
		$(CC) -o $(OBJDUMP) $(OBJDP_OBJS) $(CFLAGS)

clean		:
		$(RM) $(NM_OBJS) $(OBJDP_OBJS)
		@$(RM) *.c~
		@$(RM) *#
		@$(RM) $(DIR_NM)/*#
		@$(RM) $(DIR_NM)/*.c~

fclean		:	clean
		$(RM) $(NM) $(OBJDUMP)

re		:	fclean all
