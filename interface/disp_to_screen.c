/*
** disp_to_screen.c for disp in /home/duhieu_b/Prog_elem/sudoki-bi/interface
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 13:23:20 2016 benjamin duhieu
** Last update Sun Feb 28 14:29:25 2016 benjamin duhieu
*/

#include "sudoki.h"

void		disp_grid(t_bunny_pixelarray *pix, t_bunny_pixelarray *grid)
{
  unsigned	*pixel;
  unsigned	*board;
  int		i;
  int		j;

  pixel = (unsigned *)pix->pixels;
  board = (unsigned *)grid->pixels;
  i = -1;
  while (++i < grid->clipable.clip_height)
    {
      j = -1;
      while (++j < grid->clipable.clip_width)
	pixel[(((WIDTH / 2) - (grid->clipable.clip_width / 2)) + j) +
	      (((HEIGHT / 2) - (grid->clipable.clip_height / 2)) + i)
	      * pix->clipable.clip_width] =
	  board[j + i * grid->clipable.clip_width];
    }
}
