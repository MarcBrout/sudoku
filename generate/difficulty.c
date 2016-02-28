/*
** difficulty.c for sudoku in /home/brout_m/RENDU/CPE/sudoki-bi
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun Feb 28 12:50:41 2016 marc brout
** Last update Sun Feb 28 13:05:36 2016 marc brout
*/

#include <stdio.h>
#include <stdlib.h>
#include "generate.h"

int	*difficultytab()
{
  int	*tab;

  if (!(tab = malloc(sizeof(int) * 10)))
    return (NULL);
  tab[0] = 0;
  tab[1] = 8;
  tab[2] = 13;
  tab[3] = 18;
  tab[4] = 23;
  tab[5] = 28;
  tab[6] = 33;
  tab[7] = 48;
  tab[8] = 53;
  tab[9] = 58;
  return (tab);
}

int	show_tab(t_square *root, int **tab, int size)
{
  int	i;
  int	nb;

  i = 0;
  while (i < size)
    {
      if (!(i % 9))
	printf("|");
      if (tab[1][i])
	{
	  if ((nb = get_list_elem(root, tab[0][i])) < 0)
	    return (1);
	  printf(" %d", nb);
	}
      else
	printf("  ");
      i += 1;
      if (!(i % 9))
	printf("|\n");
    }
  return (0);
}
