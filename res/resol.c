/*
** resol.c for resol in /home/duhieu_b/Prog_elem/sudoki-bi/res
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Feb 27 11:04:33 2016 benjamin duhieu
** Last update Sun Feb 28 00:22:01 2016 benjamin duhieu
*/

#include <stdio.h>
#include "sudoki.h"

int	chk_line(char **grille, t_case *posit, int nbr)
{
  int	k;

  k = -1;
  while (++k < 9)
    {
      if (k != posit->pos.y && grille[posit->pos.x][k] == nbr + 48)
	return (0);
    }
  return (1);
}

int	chk_column(char **grille, t_case *posit, int nbr)
{
  int	k;

  k = -1;
  while (++k < 9)
    {
      if (k != posit->pos.x && grille[k][posit->pos.y] == nbr + 48)
	return (0);
    }
  return (1);
}

int	chk_box(char **grille, t_case *posit, int nbr)
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
	  [3 * (posit->pos.y / 3) + k % 3] == nbr + 48)
	return (0);
    }
  return (1);
}

int		chk_all(t_case *posit, char **grille, int nbr)
{
  if (chk_line(grille, posit, nbr) == 1 &&
      chk_column(grille, posit, nbr) == 1 &&
      chk_box(grille, posit, nbr) == 1)
    return (1);
  return (0);
}

int		put_in_tab(t_case *root, t_case *posit, char **grille)
{
  int		nbr;
  int		i;

  i = 0;
  nbr = 0;
  while (root && posit != root && ++i < 100000000)
    {
      if (!check_tab(posit->tab) && (nbr = choose_nbr(posit)))
	{
	  if (chk_all(posit, grille, nbr))
	    {
	      grille[posit->pos.x][posit->pos.y] = nbr + 48;
	      posit = posit->next;
	      if (posit == root)
		return (0);
	    }
	}
      else
	{
	  init_tab(posit->tab);
	  posit = posit->prev;
	  grille[posit->pos.x][posit->pos.y] = '0';
	}
    }
  return (1);
}
