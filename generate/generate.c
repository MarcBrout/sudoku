/*
** generate.c for sudoku in /home/brout_m/RENDU/CPE/sudoki-bi/generate
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 12:10:44 2016 marc brout
** Last update Sat Feb 27 17:41:36 2016 marc brout
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "generate.h"

t_square		*create_square_list(int size)
{
  int			i;
  t_square		*root;

  i = 0;
  if (!(root = malloc(sizeof(t_square))))
    return (NULL);
  root->next = root;
  root->prev = root;
  while (i < size)
    {
      if (add_one_square_to_root(root, i))
	return (NULL);
      i += 1;
    }
  return (root);
}

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

int		add_one_square_to_root(t_square *root, int position)
{
  t_square	*elem;

  if (!(elem = malloc(sizeof(t_square))) ||
      init_tab(elem))
    return (1);
  elem->position = position;
  elem->x = position % 9;
  elem->y = position / 9;
  elem->cube = ((((((position / 9) / 3) * 9) +
		  (((position % 9) / 3) * 3)) * 3) / 9);
  elem->value = 0;
  elem->prev = root->prev;
  elem->next = root;
  elem->prev->next = elem;
  root->prev = elem;
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

int		compare_squares(t_square *square, t_square *test, int value)
{
  if (square->x == test->x && square->value == value)
    return (1);
  if (square->y == test->y && square->value == value)
    return (1);
  if (square->cube == test->cube && square->value == value)
    return (1);
  return (0);
}


int		check_existant(int i, t_square *root,
			       t_square *square, int value)
{
  int		cur;
  t_square	*curser;

  curser = root->next;
  cur = 0;
  while (curser && curser != root && cur < i)
    {
      if (compare_squares(curser, square, value))
	return (1);
      curser = curser->next;
    }
  return (0);
}

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

void		show_tab(int **tab)
{
  int		i;

  i = -1;
  while (++i < 9)
    printf(" %d", tab[0][i]);
  printf("\n");
  i = -1;
  while (++i < 9)
    printf(" %d", tab[1][i]);
  printf("\n");
}

void		fill_list(t_square *root, int size)
{
  int		i;
  t_square	*tmp;
  int		ret;

  i = 0;
  tmp = root->next;
  while (tmp && tmp != root && i < size && i >= 0)
    {
      if ((ret = count_available_nb(tmp->avail)))
	{
	  if (!resolve_square(i, root, tmp))
	    {
	      tmp = tmp->next;
	      i += 1;
	    }
	  /* show_tab(tmp->avail); */
	}
      else
	{
	  reset_square(tmp);
	  tmp = tmp->prev;
	  tmp->value = 0;
	  i -= 1;
	}
    }
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

  if (ac < 2)
    {
      printf("Usage: %s [INT] ... difficulty between 0 and 5.\n", av[0]);
      return (1);
    }
  srand(time(NULL));
  root = create_square_list(81);
  fill_list(root, 81);
  show_tab_int(root, 81, (atoi(av[1]) + 1));
  return (0);
}
