/*
** resol.c for resol in /home/duhieu_b/Prog_elem/sudoki-bi/res
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Feb 27 11:04:33 2016 benjamin duhieu
** Last update Sat Feb 27 20:09:26 2016 benjamin duhieu
*/

#include <stdio.h>
#include "sudoki.h"

int	chk_line(char **grille, t_case *posit)
{
  int	k;

  k = -1;
  while (++k < 9)
    {
      if (k != posit->pos.y && grille[posit->pos.x][k] == posit->count + 48)
	{
	  printf("chk_line :grille[%d][%d] = %d--------- && posx = %d && posx = %d\n",
		 posit->pos.x, k,
		 grille[posit->pos.x][k], posit->pos.x, posit->pos.y);
	  return (0);
	}
    }
  /* printf("c\n"); */
  return (1);
}

int	chk_column(char **grille, t_case *posit)
{
  int	k;

  k = -1;
  while (++k < 9)
    {
      if (k != posit->pos.x && grille[k][posit->pos.y] == posit->count + 48)
	{
	  printf("chk_col : grille[%d][%d] = %d--------- && posx = %d && posx = %d\n",
		 k, posit->pos.y,
		 grille[k][posit->pos.y], posit->pos.x, posit->pos.y);
	  return (0);
	}
    }
  /* printf("b\n"); */
  return (1);
}

int	chk_box(char **grille, t_case *posit)
{
  int	k;
  int	a;

  k = -1;
  a = -1;
  while (++k < 9)
    {
      if (k % 3 == 0)
	a++;
      if ((3 * (posit->pos.x / 3) + a) != posit->pos.x &&
	  (3 * (posit->pos.y / 3) + k % 3) != posit->pos.y
	  && grille[3 * (posit->pos.x / 3) + a ]
	  [3 * (posit->pos.y / 3) + k % 3] == posit->count + 48)
	{
	  printf("chk_box :grille[%d][%d] = %d--------- && posx = %d && posx = %d\n",
		 3 * (posit->pos.x / 3) + a, 3 * (posit->pos.y / 3) + k % 3,
		 grille[3 * (posit->pos.x / 3) + a][3 * (posit->pos.y / 3) + k % 3], posit->pos.x, posit->pos.y);
	  return (0);
	}
    }
  /* printf("a\n"); */
  return (1);
}

void		show_tab(char **grille)
{
  int		y;
  int		x;

  y = -1;
  printf("|------------------|\n");
  while (++y < 9)
    {
      x = -1;
      printf("|");
      while (++x < 9)
	printf(" %c", grille[y][x]);
      printf("|\n");
    }
  printf("|------------------|\n");
}

int		put_in_tab(t_case *root, t_case *posit, char **grille)
{
  int		i;

  i = 0;
  while (root && posit != root)
    {
      printf("i = %d\n", i);
      show_tab(grille);
      if (posit->count <= 9)
	{
	  if (chk_line(grille, posit) == 1 && chk_column(grille, posit) == 1 &&
	      chk_box(grille, posit) == 1)
	    {
	      /* if (posit->count > 9) */
	      /*   posit->count -= 10; */
	      grille[posit->pos.x][posit->pos.y] = posit->count + 48;
	      printf("go forward = %d, grille[%d][%d] = %d\n", posit->count, posit->pos.x, posit->pos.y, grille[posit->pos.x][posit->pos.y]);
	      posit->count++;
	      posit = posit->next;
	      i++;
	      if (posit == root)
		return (0);
	      printf("next = %d\n", posit->count);
	    }
	  else
	    posit->count++;
	}
      else
	{
	  i--;
	  printf("go backward = %d\n", posit->count);
	  posit->count = 1;
	  grille[posit->pos.x][posit->pos.y] = ' ';
	  posit = posit->prev;
	  printf("prev_count = %d\n", posit->count);
	  grille[posit->pos.x][posit->pos.y] = ' ';
	}
     }
  return (1);
}
