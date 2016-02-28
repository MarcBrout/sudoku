##
## Makefile for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi/interface
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Sun Feb 28 13:19:08 2016 marc brout
## Last update Sun Feb 28 13:32:12 2016 marc brout
##

SRCP	=	./

SRC	=	$(SRCP)main.c \
		$(SRCP)free_game.c \
		$(SRCP)game_check.c \
		$(SRCP)get_next_line.c \
		$(SRCP)list_game.c \

OBJS	=	$(SRC:.c=.o)

NAME	=	sudoku_game

CC      =	gcc -g

CFLAGS  =	-W -Wall -Werror

CFLAGS	+=	 -I../include -I/home/${USER}/.froot/include/lapin

LDFLAGS =	-L/home/${USER}/.froot/lib \
		-llapin \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-lm \

RM      =	rm -f

.c.o:
		$(CC) -c $< -o $@ $(CFLAGS)

$(NAME): 	$(OBJS)
		@$(CC) -o $(SRC) $(LDFLAGS)

all:		$(NAME)

clean:
		@$(RM) $(OBJS)

fclean: 	clean
		@$(RM) $(NAME)

re: 		fclean all
