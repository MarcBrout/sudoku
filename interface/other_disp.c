/*
** other_disp.c for other in /home/duhieu_b/Prog_elem/sudoki-bi/interface
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 22:08:26 2016 benjamin duhieu
** Last update Sun Feb 28 23:44:30 2016 marc brout
*/

#include "sudoki.h"

void		print_game(t_main *sudoki);
{
  t_bunny_position	pos;

  fill_screen(sudoki->pix);
  pos.x = 5;
  pos.y = 5;
  disp_logo(sudoki->nbr.logo, sudoki->pix, &pos);
  pos.x = 650;
  pos.y = 35;
  disp_logo(sudoki->nbr.creator, sudoki->pix, &pos);
  pos.x = 10;
  pos.y = 300;
  disp_logo(sudoki->nbr.inst, sudoki->pix, &pos);
  disp_grid_black(sudoki->pix);
  disp_blank(sudoki->pix);
  put_nbr(&sudoki->nbr, sudoki->cursudo->squares, sudoki->pix);
  position_square(sudoki->cursudo->cursquare, sudoki->pix);
}

void		new_nbr(t_list *elem, t_bunny_pixelarray *pix, unsigned *pixel)
{
  unsigned	*nb;
  int		i;
  int		j;
  int		a;

  nb = (unsigned *)nbr->number[elem->value - 1]->pixels;
  a = (elem->x % 9) / 3;
  i = -1;
  while (++i < nbr->number[elem->value - 1]->clipable.clip_height)
    {
      j = -1;
      while (++j < nbr->number[elem->value - 1]->clipable.clip_width)
	pixel[(((WIDTH / 2) - 195) + (elem->x * 53) + 2 * elem->x + j - a + 5) +
	      (((HEIGHT / 2) - 195) + (elem->y * 53) + 2 * elem->y + i)
	      * pix->clipable.clip_width] =
	  nb[j + i * nbr->number[elem->value - 1]->clipable.clip_width];
    }
}

void		block(t_list *elem, t_bunny_pixelarray *pix)
{
  t_color	*board;
  int		i;
  int		j;
  int		a;
  int		b;
  int		tot;

  board = (t_color *)pix->pixels;
  i = -1;
  a = (elem->x % 9) / 3;
  b = (elem->y % 9) / 3;
  while (++i < 52 - b)
    {
      j = -1;
      while (++j < 52 - a)
	{
	  tot = (((WIDTH / 2) - 195) + (elem->x * 53) + 2 * elem->x - a + j) +
	    (((HEIGHT / 2) - 195) + (elem->y * 53) + 2 * elem->y - b + i)
	    * pix->clipable.clip_width;
	  board[tot].argb[1] -= 50;
	}
    }
}

void		block_case(t_list *square, t_bunny_pixelarray *pix)
{
  t_list	*elem;

  elem = square->next;
  while (elem != square)
    {
      if (elem->lock)
	block(elem, pix);
      elem = elem->next;
    }
}
