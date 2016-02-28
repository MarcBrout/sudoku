/*
** main.c for main in /home/duhieu_b/Prog_elem/sudoki-bi/interface
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 12:00:47 2016 benjamin duhieu
** Last update Sun Feb 28 22:27:29 2016 marc brout
*/

#include <unistd.h>
#include "sudoki.h"

void		fill_screen(t_bunny_pixelarray *pix)
{
  unsigned	*pixel;
  int		total;
  int		i;

  pixel = (unsigned *)pix->pixels;
  i = -1;
  total = WIDTH * HEIGHT;
  while (++i < total)
    pixel[i] = WHITE;
}

t_bunny_response	main_loop(void	*data)
{
  t_main		*sudoki;

  sudoki = data;
  if ((sudoki->vic || sudoki->lose) && sudoki->nbr.x > 820)
    sudoki->nbr.x--;
  fill_screen(sudoki->pix);
  disp_grid_black(sudoki->pix);
  disp_blank(sudoki->pix);
  put_nbr(&sudoki->nbr, sudoki->cursudo->squares, sudoki->pix);
  position_square(sudoki->cursudo->cursquare, sudoki->pix);
  if (sudoki->vic)
    print_victory(sudoki->pix, sudoki->nbr.victory, sudoki->nbr.x);
  if (sudoki->lose)
    print_victory(sudoki->pix, sudoki->nbr.defeat, sudoki->nbr.x);
  bunny_blit(&(sudoki->win->buffer), &(sudoki->pix->clipable), NULL);
  bunny_display(sudoki->win);
  return (GO_ON);
}

int	init_main(t_main *sudoki)
{
  if (!(sudoki->pix = bunny_new_pixelarray(WIDTH, HEIGHT)) ||
      !(sudoki->win = bunny_start(WIDTH, HEIGHT, false, "sudoku")))
    return (1);
  if (!(sudoki->nbr.number[0] = bunny_load_pixelarray(NUM1)) ||
      !(sudoki->nbr.number[1] = bunny_load_pixelarray(NUM2)) ||
      !(sudoki->nbr.number[2] = bunny_load_pixelarray(NUM3)) ||
      !(sudoki->nbr.number[3] = bunny_load_pixelarray(NUM4)) ||
      !(sudoki->nbr.number[4] = bunny_load_pixelarray(NUM5)) ||
      !(sudoki->nbr.number[5] = bunny_load_pixelarray(NUM6)) ||
      !(sudoki->nbr.number[6] = bunny_load_pixelarray(NUM7)) ||
      !(sudoki->nbr.number[7] = bunny_load_pixelarray(NUM8)) ||
      !(sudoki->nbr.number[8] = bunny_load_pixelarray(NUM9)) ||
      !(sudoki->nbr.victory = bunny_load_pixelarray(VICTORY)) ||
      !(sudoki->nbr.defeat = bunny_load_pixelarray(DEFEAT)))
    return (1);
  if (!(sudoki->eff = bunny_load_effect(MOVE)))
    return (1);
  bunny_sound_volume(&sudoki->eff->sound, 5);
  return (0);
}

int		init_game_lists(t_main *data)
{
  t_sudoku	*tmp;

  tmp = data->sudoki->next;
  while (tmp)
    {
      if (!(tmp->squares = new_sudoku(tmp, 81)))
	return (1);
      tmp->cursquare = tmp->squares->next;
      tmp = tmp->next;
    }
  return (0);
}

int		main(int argc, char **argv)
{
  t_main	sudoki;

  if (argc > 1 || !argv)
    return (my_puterror
	    ("Usage : ./sudoki-bi use a valid map on the standard input (0).\n"));
  sudoki.sudoki = NULL;
  if (!(sudoki.sudoki = parse_input()))
    return (1);
  sudoki.vic = 0;
  sudoki.lose = 0;
  sudoki.nbr.x = WIDTH;
  sudoki.cursudo = sudoki.sudoki->next;
  if (init_main(&sudoki) || init_game_lists(&sudoki))
    return (1);
  bunny_set_key_response(keyboard);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(sudoki.win, 60, &sudoki);
  delete_clip(&sudoki);
  bunny_stop(sudoki.win);
  bunny_delete_sound(&sudoki.eff->sound);
  free_sudoku(sudoki.sudoki);
  return (0);
}
