/*
** disp_to_screen.c for disp in /home/duhieu_b/Prog_elem/sudoki-bi/interface
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 13:23:20 2016 benjamin duhieu
** Last update Sun Feb 28 18:43:38 2016 marc brout
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

void		position_square(t_list *square, t_bunny_pixelarray *grid)
{
  unsigned	*board;
  int		i;
  int		j;

  board = (unsigned *)grid->pixels;
  i = -1;
  while (++i < 55)
    {
      j = -1;
      while (++j < 55)
	board[((square->x * 55) + j) + ((square->y * 55) + i) *
	      grid->clipable.clip_width] = GREY;
    }
}

void		put_nbr(t_image *nbr, t_list *sudo)
{
  t_list	*elem;
  unsigned	*board;
  unsigned	*nb;
  int		i;
  int		j;

  board = (unsigned *)nbr->grid->pixels;
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
		board[((elem->x * 55) + j) +
		      ((elem->y * 55) + i) * nbr->grid->clipable.clip_width] =
		  nb[j + i * nbr->number[elem->value - 1]->clipable.clip_width];
	    }
	}
      elem = elem->next;
    }
}

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
