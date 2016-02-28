##
## Makefile for Makefile in /home/duhieu_b/infographie/rendu/gfx_tekgui
##
## Made by benjamin duhieu
## Login   <duhieu_b@epitech.net>
##
## Started on  Sat Feb 13 17:14:02 2016 benjamin duhieu
## Last update Sun Feb 28 13:10:00 2016 benjamin duhieu
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

CFLAGS	+=	-I/home/${USER}/.froot/include/lapin -I../include

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
