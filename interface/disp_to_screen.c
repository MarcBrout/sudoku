/*
** disp_to_screen.c for disp in /home/duhieu_b/Prog_elem/sudoki-bi/interface
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 13:23:20 2016 benjamin duhieu
** Last update Sun Feb 28 19:42:10 2016 benjamin duhieu
*/

#include <stdio.h>
#include "sudoki.h"

/* void		go_to_red(t_list *squares, t_list *root, t_bunny_pixelarray *grid) */
/* { */
/*   t_list	*red; */
/*   unsigned	*board; */
/*   int		i; */
/*   int		j; */

/*   board	= (unsigned *)grid->pixels; */
/*   red = root->next; */
/*   while (red != root) */
/*     { */
/*       if (red->x == squares->x || red->y == squares->y || */
/* 	  red->cube == squares->cube) */
/* 	{ */
/* 	  i = -1; */
/* 	  while (++i < 51) */
/* 	    { */
/* 	      j = -1; */
/* 	      while (++j < 51) */
/* 		board[((5 * (red->cube % 3 + 1)) / 2 + ((red->x * 55) + j)) + */
/* 		      ((red->y * 55) + i + (5 * (red->cube / 3 + 1)) / 2) * */
/* 		       grid->clipable.clip_width] = RED; */
/* 	    } */
/* 	} */
/*       red = red->next; */
/*     } */
/* } */

/* void		wrong_number(t_list *squares, t_list *root, t_bunny_pixelarray *grid) */
/* { */
/*   t_list	*elem; */

/*   elem = root->next; */
/*   while (elem != root) */
/*     { */
/*       if (elem->x == squares->x || elem->y == squares->y || */
/* 	  elem->cube == squares->cube) */
/* 	{ */
/* 	  if (elem->value == squares->value) */
/* 	    { */
/* 	      go_to_red(squares, root, grid); */
/* 	      break ; */
/* 	    } */
/* 	} */
/*       elem = elem->next; */
/*     } */
/* } */

void		position_square(t_list *square, t_bunny_pixelarray *pix)
{
  unsigned	*board;
  int		i;
  int		j;

  board = (unsigned *)pix->pixels;
  i = -1;
  while (++i < 52)
    {
      j = -1;
	while (++j < 52)
	  {
	    board[(((WIDTH / 2) - 195) + square->x * 53 + j + 5) +
		  (((HEIGHT / 2) - 195) + square->y * 53 + i + 5)
		  * pix->clipable.clip_width] = GREY;
	  }
    }
}

void		put_nbr(t_image *nbr, t_list *sudo, t_bunny_pixelarray *pix)
{
  t_list	*elem;
  unsigned	*nb;
  unsigned	*pixel;
  int		i;
  int		j;

  pixel = (unsigned *)pix->pixels;
  elem = sudo->next;
  while (elem != sudo)
    {
      if (elem->value)
	{
	  nb = (unsigned *)nbr->number[elem->value - 1]->pixels;
	  i = -1;
	  while (++i < nbr->number[elem->value - 1]->clipable.clip_height)
	    {
	      j = -1;
	      while (++j < nbr->number[elem->value - 1]->clipable.clip_width)
		pixel[(((WIDTH / 2) - 195) + sudo->x * 53 + j + 5) +
		      (((HEIGHT / 2) - 195) + sudo->y * 53 + i + 5)
		      * pix->clipable.clip_width] =
		  nb[j + i * nbr->number[elem->value - 1]->clipable.clip_width];
	    }
	}
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
