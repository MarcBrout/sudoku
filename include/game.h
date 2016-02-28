/*
** game.h for game in /home/duhieu_b/Prog_elem/sudoki-bi
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 12:01:44 2016 benjamin duhieu
** Last update Sun Feb 28 15:44:08 2016 marc brout
*/

#ifndef GAME_H_
# define GAME_H_
# define WIDTH 1024
# define HEIGHT 768
# define NUM1 ../interface/jpg/gold1.jpg
# define NUM2 ../interface/jpg/gold2.jpg
# define NUM3 ../interface/jpg/gold3.jpg
# define NUM4 ../interface/jpg/gold4.jpg
# define NUM5 ../interface/jpg/gold5.jpg
# define NUM6 ../interface/jpg/gold6.jpg
# define NUM7 ../interface/jpg/gold7.jpg
# define NUM8 ../interface/jpg/gold8.jpg
# define NUM9 ../interface/jpg/gold9.jpg

# include "lapin.h"
# incude "parser.h"

typedef struct		s_list
{
  int			position;
  int			x;
  int			y;
  int			cube;
  int			value;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef	struct		s_image
{
  t_bunny_pixelarray	*grid;
  t_bunny_pixelarray	*number[9];
}			t_image;

typedef struct		s_main
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_image		nbr;
  t_square		*sudoki;
  t_list		list;
  int			first_game;
}			t_main;

/*
** Init graphics main : main.c
*/

int	init_main(t_main *);
t_bunny_response	main_loop(void *);
void	fill_screen(t_bunny_pixelarray *);

#endif /* !GAME_H_ */
