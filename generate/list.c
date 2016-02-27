/*
** list.c for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi/generate
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 20:41:09 2016 marc brout
** Last update Sat Feb 27 21:07:32 2016 marc brout
*/

#include <stdlib.h>
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
