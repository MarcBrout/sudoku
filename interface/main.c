/*
** main.c for main in /home/duhieu_b/Prog_elem/sudoki-bi/interface
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 12:00:47 2016 benjamin duhieu
** Last update Sun Feb 28 13:01:39 2016 benjamin duhieu
*/

#include <string.h>
#include "sudoki.h"

int		check_str(const char *str)
{
  int		i;

  i = -1;
  while (str && str[++i])
    if (str[i] != ' ' && str[i] < '0' && str[i] > '9')
      return (1);
  return (0);
}

int		parse_tab(t_sudoku *sudo)
{
  char		*str;
  int		y;

  y = -1;
  while (++y < 9)
    {
      if (!(str = get_next_line(0)))
	return (my_puterror(MALLOC_ERROR));
      if (strlen(str) != 20)
	return (my_puterror(MAP_ERROR));
      fill_line(sudo->tab[y], str);
      if (check_str(sudo->tab[y]))
	return (my_puterror(MAP_ERROR));
      freestr(str);
    }
  return (0);
}

t_sudoku	*parse_one_input()
{
  t_sudoku	*sudo;

  if (!(sudo = malloc(sizeof(t_sudoku))))
    return (my_puterrornull(MALLOC_ERROR));
  sudo->valid = 1;
  if (!(sudo->tab = set_tab()))
    return (NULL);
  sudo->next = NULL;
  if (parse_tab(sudo))
    return (NULL);
  return (sudo);
}

t_sudoku	*parse_input()
{
  char		*str;
  t_sudoku	*sudo;
  t_sudoku	*tmp;

  if (!(sudo = malloc(sizeof(t_sudoku))))
    return (my_puterrornull(MAP_ERROR));
  sudo->valid = 2;
  sudo->next = NULL;
  while ((str = get_next_line(0)))
    {
      if (strlen(str) != 20)
	return (my_puterrornull(MAP_ERROR));
      if (!(tmp = parse_one_input()))
	return (NULL);
      freestr(str);
      is_it_valid(tmp);
      check_integrity(tmp);
      add_to_end_list(sudo, tmp);
      if (!(str = get_next_line(0)) || strlen(str) != 20)
	return (my_puterrornull(MAP_ERROR));
      freestr(str);
    }
  freestr(str);
  return (sudo);
}

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
  bunny_blit(&(sudoki->win->buffer), &(sudoki->pix->clipable), NULL);
  bunny_display(sudoki->win);
  return (GO_ON);
}

int	init_main(t_main *sudoki)
{
  sudoki->pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  sudoki->win = bunny_start(WIDTH, HEIGHT, false, "sudoku");
  if (!(sudoki->nbr.grid = bunny_load_pixelarray("jpg/grid.jpg")))
    return (1);
  if (!(sudoki->nbr.number[0] = bunny_load_pixelarray("jpg/gold1.jpg")) ||
      !(sudoki->nbr.number[1] = bunny_load_pixelarray("jpg/gold2.jpg")) ||
      !(sudoki->nbr.number[2] = bunny_load_pixelarray("jpg/gold3.jpg")) ||
      !(sudoki->nbr.number[3] = bunny_load_pixelarray("jpg/gold4.jpg")) ||
      !(sudoki->nbr.number[4] = bunny_load_pixelarray("jpg/gold5.jpg")) ||
      !(sudoki->nbr.number[5] = bunny_load_pixelarray("jpg/gold6.jpg")) ||
      !(sudoki->nbr.number[6] = bunny_load_pixelarray("jpg/gold7.jpg")) |
      !(sudoki->nbr.number[7] = bunny_load_pixelarray("jpg/gold8.jpg")) ||
      !(sudoki->nbr.number[8] = bunny_load_pixelarray("jpg/gold9.jpg")))
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
  init_main(&sudoki);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(sudoki.win, 60, &sudoki);
  bunny_delete_clipable(&(sudoki.pix->clipable));
  bunny_stop(sudoki.win);
  free_sudoku(tmp);
  return (0);
}
