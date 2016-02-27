/*
** main.c for main in /home/duhieu_b/Prog_elem/sudoki-bi/res
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Feb 26 22:16:06 2016 benjamin duhieu
** Last update Sat Feb 27 23:08:48 2016 benjamin duhieu
*/

#include <stdio.h>
#include <stdlib.h>
#include "sudoki.h"

void	init_tab(int *tab)
{
  int	i;

  i = -1;
  while (++i < 9)
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
      if (res(elem->tab))
	elem->valid = 1;
      else
	elem->valid = 0;
      elem = elem->next;
    }
}
