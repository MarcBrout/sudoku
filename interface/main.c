/*
** main.c for main in /home/duhieu_b/Prog_elem/sudoki-bi/interface
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 12:00:47 2016 benjamin duhieu
** Last update Sun Feb 28 16:32:35 2016 benjamin duhieu
*/

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
  fill_screen(sudoki->pix);
  disp_grid(sudoki->pix, sudoki->nbr.grid);
  bunny_blit(&(sudoki->win->buffer), &(sudoki->pix->clipable), NULL);
  bunny_display(sudoki->win);
  return (GO_ON);
}

int	init_main(t_main *sudoki)
{
  if (!(sudoki->pix = bunny_new_pixelarray(WIDTH, HEIGHT)) ||
      !(sudoki->win = bunny_start(WIDTH, HEIGHT, false, "sudoku")))
    return (1);
  if ((sudoki->nbr.grid = bunny_load_pixelarray(GRID)) == NULL)
    return (1);
  if (!(sudoki->nbr.number[0] = bunny_load_pixelarray(NUM1)) ||
      !(sudoki->nbr.number[1] = bunny_load_pixelarray(NUM2)) ||
      !(sudoki->nbr.number[2] = bunny_load_pixelarray(NUM3)) ||
      !(sudoki->nbr.number[3] = bunny_load_pixelarray(NUM4)) ||
      !(sudoki->nbr.number[4] = bunny_load_pixelarray(NUM5)) ||
      !(sudoki->nbr.number[5] = bunny_load_pixelarray(NUM6)) ||
      !(sudoki->nbr.number[6] = bunny_load_pixelarray(NUM7)) |
      !(sudoki->nbr.number[7] = bunny_load_pixelarray(NUM8)) ||
      !(sudoki->nbr.number[8] = bunny_load_pixelarray(NUM9)))
    return (1);
  return (0);
}

int		main(int argc, char **argv)
{
  t_sudoku	*tmp;
  t_main	sudoki;

  if (argc > 1 || !argv)
    return (my_puterror
	    ("Usage : ./sudoki-bi use a valid map on the standard input (0).\n"));
  tmp = NULL;
  if (!(tmp = parse_input()))
    return (1);
  if (init_main(&sudoki))
    return (1);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(sudoki.win, 60, &sudoki);
  bunny_delete_clipable(&(sudoki.pix->clipable));
  bunny_stop(sudoki.win);
  free_sudoku(tmp);
  return (0);
}
