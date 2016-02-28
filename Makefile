##
## Makefile for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Feb 25 16:34:58 2016 marc brout
## Last update Sun Feb 28 12:57:52 2016 marc brout
##

SRCR		=	res/

SRCP		=	parsing/

SRCM		=	main/

SRCG		=	generate/

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
			$(SRCR)error.c \
			$(SRCR)fill_tab.c \
			$(SRCR)check.c

SRCGEN		=	$(SRCG)generate.c \
			$(SRCG)list.c \
			$(SRCG)free.c \
			$(SRCG)check.c \
			$(SRCG)array.c \
			$(SRCG)show.c \
			$(SRCG)difficulty.c

OBJS    	=	$(SRC:.c=.o)

OBJSGEN		=	$(SRCGEN:.c=.o)

NAME    	=	bin/sudoki-bi

GENERATOR	=	bin/generator-sudoki-bi

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

bonus:			$(OBJSGEN)
			$(CC) -o $(GENERATOR) $(OBJSGEN) $(LDFLAGS)

all:			$(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(OBJSGEN)

fclean:			clean
			$(RM) $(NAME)
			$(RM) $(GENERATOR)

re:			fclean all
