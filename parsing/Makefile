##
## Makefile for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Feb 25 16:34:58 2016 marc brout
## Last update Sat Feb 27 01:22:52 2016 marc brout
##

SRCP		= ./

SRC     	= $(SRCP)parsing.c \
		$(SRCP)check.c \
		$(SRCP)show.c \
		$(SRCP)tab_and_list.c \
		$(SRCP)get_next_line.c \
		$(SRCP)free.c

OBJS    	= $(SRC:.c=.o)

NAME    	= sudoki-bi

CC      	= gcc -g

CFLAGS  	=  -W -Wall -Werror

HDFLAGS 	= -I../include/

LDFLAGS 	=

RM      	= rm -f

.phony: 

.c.o:
	$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
