/*
** disp_to_screen.c for disp in /home/duhieu_b/Prog_elem/sudoki-bi
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Feb 29 00:41:49 2016 benjamin duhieu
** Last update Mon Feb 29 00:41:53 2016 benjamin duhieu
*/

#include <stdio.h>
#include "sudoki.h"

void		disp_logo(t_bunny_pixelarray *img, t_bunny_pixelarray *pix,
			  t_bunny_position *pos)
{
  t_color	*pixel;
  t_color	*title;
  int		i;
  int		j;

  pixel = (t_color *)pix->pixels;
  title = (t_color *)img->pixels;
  i = -1;
  while (++i < img->clipable.clip_height)
    {
      j = -1;
      while (++j < img->clipable.clip_width)
	if (title[j + i * img->clipable.clip_width].argb[0] != 0)
	  pixel[pos->x + j + (pos->y + i) * pix->clipable.clip_width] =
	    title[j + i * img->clipable.clip_width];
    }
}

void		position_square(t_list *square, t_bunny_pixelarray *pix)
{
  t_color	*board;
  int		i;
  int		j;
  int		a;
  int		b;
  int		tot;

  board = (t_color *)pix->pixels;
  i = -1;
  a = (square->x % 9) / 3;
  b = (square->y % 9) / 3;
  while (++i < 52 - b)
    {
      j = -1;
	while (++j < 52 - a)
	  {
	    tot = (((WIDTH / 2) - 195) + (square->x * 53) + 2 * square->x - a + j) +
	      (((HEIGHT / 2) - 195) + (square->y * 53) + 2 * square->y - b + i)
	      * pix->clipable.clip_width;
	    board[tot].argb[0] -= 20;
	    board[tot].argb[1] -= 20;
	    board[tot].argb[2] -= 20;
	  }
    }
}

void		put_nbr(t_image *nbr, t_list *sudo, t_bunny_pixelarray *pix)
{
  t_list	*elem;
  unsigned	*pixel;

  pixel = (unsigned *)pix->pixels;
  elem = sudo->next;
  while (elem != sudo)
    {
      if (elem->value)
	new_nbr(nbr, elem, pix, pixel);
      elem = elem->next;
    }
}

void		disp_blank(t_bunny_pixelarray *pix)
{
  int		i;
  int		j;
  unsigned	*pixel;

  pixel = (unsigned *)pix->pixels;
  i = -1;
  while (++i < 504)
    {
      j = -1;
      if ((i > 7 && i < 59) || (i > 60 && i < 113) || (i > 114 && i < 167)
	  || (i > 171 && i < 224) || (i > 225 && i < 278) || (i > 279 && i < 331)
	  || (i > 335 && i < 387) || (i > 388 && i < 440) || (i > 441 && i < 496))
	while (++j < 504)
	  {
	    if ((j > 7 && j < 59) || (j > 60 && j < 113) || (j > 114 && j < 167)
	    	|| (j > 171 && j < 224) || (j > 225 && j < 278) || (j > 279 && j < 331)
	    	|| (j > 335 && j < 387) || (j > 388 && j < 440) || (j > 441 && j < 496))
	      pixel[(((WIDTH / 2) - 202) + j) + (((HEIGHT / 2) - (202)) + i)
		    * pix->clipable.clip_width] = WHITE;
	  }
    }
}

void		disp_grid_black(t_bunny_pixelarray *pix)
{
  unsigned	*pixel;
  int		i;
  int		j;

  pixel = (unsigned *)pix->pixels;
  i = -1;
  while (++i < 504)
    {
      j = -1;
      while (++j < 504)
	pixel[(((WIDTH / 2) - 202) + j) + (((HEIGHT / 2) - (202)) + i)
	      * pix->clipable.clip_width] = BLACK;
    }
}
