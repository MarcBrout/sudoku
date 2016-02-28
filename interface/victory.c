/*
** victory.c for sudoku in /home/brout_m/RENDU/CPE/sudoki-bi
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun Feb 28 21:29:36 2016 marc brout
** Last update Sun Feb 28 21:54:13 2016 marc brout
*/

#include "game.h"

void			print_victory(t_bunny_pixelarray *back,
				      t_bunny_pixelarray *victory,
				      int x)
{
  t_bunny_position	pback;
  t_bunny_position	pvic;
  unsigned int		*pix;
  unsigned int		*vic;

  pvic.y = -1;
  pback.y = 200;
  pix = back->pixels;
  vic = victory->pixels;
  while (++pvic.y < victory->clipable.clip_height && ++pback.y)
    {
      pvic.x = -1;
      pback.x = x;
      while (++pvic.x < victory->clipable.clip_width && ++pback.x <
	     back->clipable.clip_width)
	pix[pback.x + pback.y * back->clipable.clip_width] =
	  vic[pvic.x + pvic.y * victory->clipable.clip_width];
    }
}
