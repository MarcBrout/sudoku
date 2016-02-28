/*
** game.h for game in /home/duhieu_b/Prog_elem/sudoki-bi
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 12:01:44 2016 benjamin duhieu
** Last update Sun Feb 28 16:32:57 2016 marc brout
*/

#ifndef GAME_H_
# define GAME_H_
# define WIDTH 1024
# define HEIGHT 768
# define GRID "./interface/bmp/grid.bmp"
# define NUM1 "./interface/bmp/gold1.bmp"
# define NUM2 "./interface/bmp/gold2.bmp"
# define NUM3 "./interface/bmp/gold3.bmp"
# define NUM4 "./interface/bmp/gold4.bmp"
# define NUM5 "./interface/bmp/gold5.bmp"
# define NUM6 "./interface/bmp/gold6.bmp"
# define NUM7 "./interface/bmp/gold7.bmp"
# define NUM8 "./interface/bmp/gold8.bmp"
# define NUM9 "./interface/bmp/gold9.bmp"

# include "lapin.h"
# include "parser.h"

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
  t_sudoku		*cursudo;
  t_sudoku		*sudoki;
}			t_main;

/*
** Init graphics main : main.c
*/

int	init_main(t_main *);
t_bunny_response	main_loop(void *);
void	fill_screen(t_bunny_pixelarray *);

void	disp_grid(t_bunny_pixelarray *, t_bunny_pixelarray *);

#endif /* !GAME_H_ */
