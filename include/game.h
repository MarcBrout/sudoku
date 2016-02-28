/*
** game.h for game in /home/duhieu_b/Prog_elem/sudoki-bi
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 12:01:44 2016 benjamin duhieu
** Last update Sun Feb 28 14:48:33 2016 marc brout
*/

#ifndef GAME_H_
# define GAME_H_
# define WIDTH 1024
# define HEIGHT 768

# include "lapin.h"
# incude "parser.h"

typedef struct		s_list
{
  int			**avail;
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
  int			first_game;
}			t_main;

/*
** Init graphics main : main.c
*/

int	init_main(t_main *);
t_bunny_response	main_loop(void *);
void	fill_screen(t_bunny_pixelarray *);

#endif /* !GAME_H_ */
