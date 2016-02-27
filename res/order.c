/*
** main.c for main in /home/duhieu_b/Prog_elem/sudoki-bi/res
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Feb 26 22:16:06 2016 benjamin duhieu
** Last update Sat Feb 27 20:51:41 2016 benjamin duhieu
*/

#include <stdio.h>
#include <stdlib.h>
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

void	init_tab(int *tab)
{
  int	i;

  i = -1;
  while(++i < 9)
    tab[i] = 1;
}

int	nb_possib(char **grille)
{
  int	i;
  int	j;
  int	*tab;

  if ((tab = malloc(sizeof(int) * 10)) == NULL)
    return (1);
  tab[9] = -1;
  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	{
	  init_tab(tab);
	  if (grille[i][j] == ' ')
	    grille[i][j] = check(grille, i, j, tab);
	}
    }
  return (0);
}

int		res(char **grille)
{
  t_case	*root;

  if ((root = malloc(sizeof(t_case))) == NULL)
    return (my_puterror("Error: Malloc failed\n"));
  root->next = root;
  root->prev = root;
  if (nb_possib(grille))
    return (1);
  root = put_in_list(root, grille);
  if (put_in_tab(root, root->next, grille))
    {
      printf(":::::::");
      free_backtracing(root);
      return (1);
    }
  free_backtracing(root);
  return (0);
}

void		road_to_list(t_sudoku *sudo)
{
  t_sudoku	*elem;

  elem = sudo->next;
  while (elem != NULL)
    {
      printf("----------------------------------------------\n");
      if (res(elem->tab))
	elem->block = 1;
      else
	elem->block = 0;
      printf("elem->block = %d\n", elem->block);
      elem = elem->next;
    }
}
