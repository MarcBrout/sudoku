##
## Makefile for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Feb 25 16:34:58 2016 marc brout
## Last update Sat Feb 27 22:40:52 2016 marc brout
##

SRCP		= ./generate/

SRC     	= $(SRCP)generate.c \
		$(SRCP)array.c \
		$(SRCP)list.c \
		$(SRCP)check.c \
		$(SRCP)free.c 

OBJS    	= $(SRC:.c=.o)

NAME    	= gen-sudoki-bi

CC      	= gcc

CFLAGS  	=  -W -Wall -Werror

HDFLAGS 	= -I./include/

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
