##
## Makefile for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Feb 25 16:34:58 2016 marc brout
## Last update Sat Feb 27 12:05:12 2016 benjamin duhieu
##

SRCR		=	res/

SRCP		=	parsing/

SRCM		=	main/

SRC     	=	$(SRCM)main.c \
			$(SRCP)parsing.c \
			$(SRCP)check.c \
			$(SRCP)get_next_line.c \
			$(SRCP)show.c \
			$(SRCP)tab_and_list.c \
			$(SRCP)free.c \
			$(SRCR)order.c \
			$(SRCR)case_list.c \
			$(SRCR)resol.c \
			$(SRCR)free_back.c \
			$(SRCR)error.c

OBJS    	=	$(SRC:.c=.o)

NAME    	=	sudoki-bi

CC      	=	gcc -g

CFLAGS  	=	-W -Wall -Werror

HDFLAGS 	=	-Iinclude/

LDFLAGS 	=

RM      	=	rm -f

.phony: 

.c.o:
			$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all:			$(NAME)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
