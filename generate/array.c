/*
** array.c for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi/generate
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 20:48:13 2016 marc brout
** Last update Sat Feb 27 21:04:07 2016 marc brout
*/

#include <stdlib.h>
#include "generate.h"

int		init_tab(t_square *square)
{
  int		**tmp;

  if (!(tmp = malloc(sizeof(int *) * 3)))
    return (1);
  if (!(tmp[0] = malloc(sizeof(int) * 10)))
    return (1);
  if (!(tmp[1] = malloc(sizeof(int) * 10)))
    return (1);
  tmp[2] = NULL;
  set_tab_int(tmp, 1);
  square->avail = tmp;
  return (0);
}

void		set_tab_cell_to_nb(int **tab, int cell, int nb)
{
  int		x;

  x = 0;
  while (x < COLOMN)
    {
      if (tab[0][x] == cell)
	tab[1][x] = nb;
      x += 1;
    }
}

void		set_tab_int(int **tab, int nb)
{
  int		x;

  x = 0;
  while (x < COLOMN)
    {
      tab[0][x] = x + 1;
      tab[1][x] = nb;
      x += 1;
    }
}

int		count_available_nb(int **tab)
{
  int		total;
  int		i;

  i = 0;
  total = 0;
  while (i < COLOMN)
    {
      if (tab[1][i])
	total += 1;
      i += 1;
    }
  return (total);
}

int		rand_nb(t_square *square)
{
  int		test;

  test = rand() % 9;
  while (!square->avail[1][test])
    test = rand() % 9;
  return (test + 1);
}
