/*
** other_disp.c for other in /home/duhieu_b/Prog_elem/sudoki-bi/interface
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 22:08:26 2016 benjamin duhieu
** Last update Sun Feb 28 22:18:59 2016 benjamin duhieu
*/

#include "sudoki.h"

void		block_case(t_list *square, t_bunny_pixelarray *pix)
{
  t_color	*board;
  t_list	*elem;
  int		i;
  int		j;
  int		a;
  int		b;
  int		tot;

  elem = square->next;
  while (elem != square)
    {
      if (elem->lock)
	{
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
      elem = elem->next;
    }
}
