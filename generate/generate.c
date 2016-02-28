/*
** generate.c for sudoku in /home/brout_m/RENDU/CPE/sudoki-bi/generate
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 12:10:44 2016 marc brout
** Last update Sun Feb 28 00:44:38 2016 marc brout
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "generate.h"

int		resolve_square(int i, t_square *root, t_square *square)
{
  int		nb;

  nb = rand_nb(square);
  if (check_existant(i - 1, root, square, nb))
    {
      set_tab_cell_to_nb(square->avail, nb, 0);
      return (1);
    }
  square->value = nb;
  set_tab_cell_to_nb(square->avail, nb, 0);
  return (0);
}

void		reset_square(t_square *square)
{
  set_tab_int(square->avail, 1);
  square->value = 0;
}

int		fill_list(t_square *root, int size)
{
  int		i;
  t_square	*tmp;
  int		ret;

  i = 0;
  ret = 0;
  tmp = root->next;
  while (tmp && tmp != root && i < size && i >= 0 && (ret += 1))
    {
      if (ret >= 1000)
	return (1);
      if (count_available_nb(tmp->avail))
	{
	  if (!resolve_square(i, root, tmp) && (i += 1))
	    tmp = tmp->next;
	}
      else if (i -= 1)
	{
	  reset_square(tmp);
	  tmp = tmp->prev;
	  tmp->value = 0;
	}
    }
  return (0);
}

void		show_tab_int(t_square *root, int size, int difficulty)
{
  t_square	*curser;
  int		i;

  i = 0;
  curser = root->next;
  printf("|------------------|\n");
  while (i < size)
    {
      if (!(i % 9))
	printf("|");
      if (difficulty && !(rand () % difficulty))
	printf(" %d", curser->value);
      else
	printf("  ");
      if ((i % 9) == 8 && i != 0)
	printf("|\n");
      i += 1;
      curser = curser->next;
    }
  printf("|------------------|\n");
}

int		main(int ac, char **av)
{
  t_square	*root;
  int		ret;

  if (ac != 2 || check_str(av[1]) || atoi(av[1]) > 9 || atoi(av[1]) < 0)
    {
      printf("Usage: %s [INT] ... difficulty between 0 and 9.\n", av[0]);
      return (1);
    }
  srand(time(NULL));
  ret = 1;
  while (ret)
    {
      root = create_square_list(81);
      if ((ret = fill_list(root, 81)))
	free_square(root);
    }
  show_tab_int(root, 81, (atoi(av[1]) + 1));
  free_square(root);
  return (0);
}
