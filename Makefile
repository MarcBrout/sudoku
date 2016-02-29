##
## Makefile for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Feb 25 16:34:58 2016 marc brout
## Last update Mon Feb 29 01:31:09 2016 marc brout
##

SRCR		=	res/

SRCP		=	parsing/

SRCM		=	main/

SRCG		=	generate/

SRCI		=	interface/

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

SRCINT		=	$(SRCI)main.c \
			$(SRCI)free_game.c \
			$(SRCI)game_check.c \
			$(SRCI)get_next_line.c \
			$(SRCI)list_game.c \
			$(SRCI)error.c \
			$(SRCI)show.c \
			$(SRCI)parse_game.c \
			$(SRCI)list.c \
			$(SRCI)disp_to_screen.c \
			$(SRCI)keyboard.c \
			$(SRCI)compare.c \
			$(SRCI)victory.c \
			$(SRCI)other_disp.c \

OBJS    	=	$(SRC:.c=.o)

OBJSGEN		=	$(SRCGEN:.c=.o)

OBJSINT		=	$(SRCINT:.c=.o)

NAME    	=	bin/sudoki-bi

GENERATOR	=	bin/generator-sudoki-bi

INTERFACE	=	bin/interface-sudoki-bi

CC      	=	gcc

CFLAGS  	=	-W -Wall -Werror

HDFLAGS 	=	-Iinclude/

HDFLAGS 	+=	-I/home/${USER}/.froot/include/lapin

LDFLAGS 	=

LDFLAGSI	=	-L/home/${USER}/.froot/lib \
			-llapin \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm \

RM      	=	rm -f

.phony: 

.c.o:
			$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

bonus:			$(OBJSGEN)
			$(CC) -o $(GENERATOR) $(OBJSGEN) $(LDFLAGS)

interface:		$(OBJSINT)
			$(CC) -o $(INTERFACE) $(OBJSINT) $(LDFLAGSI)

all:			$(NAME)

clean:
			$(RM) $(OBJSINT)
			$(RM) $(OBJS)
			$(RM) $(OBJSGEN)

fclean:			clean
			$(RM) $(INTERFACE)
			$(RM) $(NAME)
			$(RM) $(GENERATOR)

re:			fclean all
