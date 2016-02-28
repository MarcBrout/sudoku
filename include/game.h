/*
** game.h for game in /home/duhieu_b/Prog_elem/sudoki-bi
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 12:01:44 2016 benjamin duhieu
** Last update Sun Feb 28 22:28:33 2016 benjamin duhieu
*/

#ifndef GAME_H_
# define GAME_H_
# define WIDTH 1024
# define HEIGHT 768
# define GREY 0xFFBDBDBD
# define MOVE "./interface/sound/menu_select.ogg"
# define LOGO "./interface/bmp/sudoku-logo.png"
# define NAME "./interface/bmp/creator.png"
# define INS  "./interface/bmp/instruction.png"
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
  t_bunny_pixelarray	*logo;
  t_bunny_pixelarray	*inst;
  t_bunny_pixelarray	*creator;
  t_bunny_pixelarray	*number[9];
}			t_image;

typedef struct		s_main
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_bunny_effect	*eff;
  t_image		nbr;
  t_sudoku		*cursudo;
  t_sudoku		*sudoki;
  int			vic;
  int			lose;
}			t_main;

/*
** Init graphics main : main.c
*/

int	init_main(t_main *);
t_bunny_response	main_loop(void *);
void	fill_screen(t_bunny_pixelarray *);

void	block_case(t_list *, t_bunny_pixelarray *);
void	disp_logo(t_bunny_pixelarray *, t_bunny_pixelarray *, t_bunny_position *);
void	disp_blank(t_bunny_pixelarray *);
void	disp_grid_black(t_bunny_pixelarray *);
void	put_nbr(t_image *, t_list *, t_bunny_pixelarray *);
void	position_square(t_list *, t_bunny_pixelarray *);

/*
** keyboard.c
*/

t_list			*move_cur(t_list *, t_list *, int, int);
void			move_cur_square(t_sudoku *, t_main *, t_bunny_keysym);
t_bunny_response	keyboard(t_bunny_event_state, t_bunny_keysym, void *);
void			input_number(t_main *data,
				     t_sudoku *sudoku,
				     t_bunny_keysym keysym);

/*
** list.c
*/

t_list	*new_sudoku(t_sudoku *, int);
void	free_list(t_list *);
void	initialize_list(char **, t_list *);
t_list	*create_list_list(int size);
int	add_one_list_to_root(t_list *, int);

/*
** free_game.c
*/

void	delete_clip(t_main *);

/*
** compare.c
*/

void	reset_grid(t_list *root);
int	compare_lists(t_list *list, t_list *test);
int	check_existant(t_list *root, t_list *list);
void	check_whole_grid(t_main *data, t_list *root);

#endif /* !GAME_H_ */
