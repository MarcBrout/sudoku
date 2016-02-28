/*
** game.h for game in /home/duhieu_b/Prog_elem/sudoki-bi
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 12:01:44 2016 benjamin duhieu
** Last update Sun Feb 28 19:25:22 2016 benjamin duhieu
*/

#ifndef GAME_H_
# define GAME_H_
# define WIDTH 1024
# define HEIGHT 768
# define GREY 0xFFBDBDBD
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

void	disp_blank(t_bunny_pixelarray *);
void	disp_grid_black(t_bunny_pixelarray *);
void	put_nbr(t_image *, t_list *, t_bunny_pixelarray *);
/* void	position_square(t_list *, t_bunny_pixelarray *); */
/* void	wrong_number(t_list *, t_list *, t_bunny_pixelarray *); */
void	go_to_red(t_list *, t_list *, t_bunny_pixelarray *);

/*
** keyboard.c
*/

void	move_cur(t_list *, t_list *, int, int);
void	move_cur_square(t_sudoku *, t_bunny_keysym);
t_bunny_response	keyboard(t_bunny_event_state, t_bunny_keysym, void *);

/*
** list.c
*/

t_list	*new_sudoku(t_sudoku *, int);
void	free_list(t_list *);
void	initialize_list(char **, t_list *);
t_list	*create_list_list(int size);
int	add_one_list_to_root(t_list *, int);

#endif /* !GAME_H_ */
