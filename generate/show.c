
/*
** show.c for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun Feb 28 11:31:00 2016 marc brout
** Last update Sun Feb 28 13:03:07 2016 marc brout
*/

#include <stdlib.h>
#include <stdio.h>
#include "generate.h"

int		get_list_elem(t_square *root, int cell)
{
  int		i;
  t_square	*tmp;

  tmp = root->next;
  i = 1;
  while (tmp && tmp != root && i < cell)
    {
      tmp = tmp->next;
      i += 1;
    }
  if (tmp != root)
    return (tmp->value);
  return (-1);
}

int	**create_tab(int size)
{
  int	**tab;

  if (!(tab = malloc(sizeof(int *) * 3)))
    return (NULL);
  tab[2] = NULL;
  if (!(tab[0] = malloc(sizeof(int) * (size + 1))))
    return (NULL);
  if (!(tab[1] = malloc(sizeof(int) * (size + 1))))
    return (NULL);
  return (tab);
}

void	init_tab_show(int **tab, int size, int nb)
{
  int	i;

  i = 0;
  while (i < size)
    {
      tab[0][i] = i + 1;
      tab[1][i] = nb;
      i += 1;
    }
}

int	count_how_many_cell(int **tab, int size)
{
  int	nb;
  int	i;

  i = 0;
  while (i < size)
    {
      if (tab[1][i])
	nb += 1;
      i += 1;
    }
  return (nb);
}

int	get_rand_valid_cell(int **tab, int size)
{
  int	nb;

  nb = rand() % size + 1;
  while (!tab[1][nb - 1])
    nb = rand() % size + 1;
  return (nb);
}
