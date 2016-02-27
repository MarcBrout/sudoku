/*
** check.c for check in /home/duhieu_b/Prog_elem/sudoki-bi/res
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Feb 27 22:30:42 2016 benjamin duhieu
** Last update Sat Feb 27 22:32:27 2016 benjamin duhieu
*/

#include "sudoki.h"

int	*line(char **grille, int i, int *tab)
{
  int	k;

  k = -1;
  while (++k < 9)
    if (grille[i][k] >= '1' && grille[i][k] <= '9')
      tab[grille[i][k] - 49] = 0;
  return (tab);
}

int	*column(char **grille, int j, int *tab)
{
  int	k;

  k = -1;
  while (++k < 9)
    if (grille[k][j] >= '1' && grille[k][j] <= '9')
      tab[grille[k][j] - 49] = 0;
  return (tab);
}

int	*box(char **grille, int i, int j, int *tab)
{
  int	a;
  int	k;

  k = -1;
  a = -1;
  while (++k < 9)
    {
      if (k % 3 == 0)
	a++;
      if (grille[3 * (i / 3) + a][3 * (j / 3) + k % 3] >= '1' &&
	  grille[3 * (i / 3) + a][3 * (j / 3) + k % 3] <= '9')
	tab[grille[3 * (i / 3) + a][3 * (j / 3) + k % 3] - 49] = 0;
    }
  return (tab);
}

int	count_possib(int *tab)
{
  int	i;
  int	res;

  i = -1;
  res = 0;
  while (++i < 9)
    if (tab[i] == 1)
      res++;
  return (res);
}

int	check(char **grille, int i, int j, int *tab)
{
  int	res;

  line(grille, i, tab);
  column(grille, j, tab);
  box(grille, i, j, tab);
  res = count_possib(tab);
  return (res);
}
