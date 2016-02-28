/*
** list.c for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi/generate
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 20:41:09 2016 marc brout
** Last update Sun Feb 28 15:47:32 2016 marc brout
*/

#include <stdlib.h>
#include "game.h"

void		free_list(t_list *root)
{
  t_list	*tmp;
  t_list	*tmp2;

  tmp = root->next;
  while (tmp && tmp != root)
    {
      tmp2 = tmp->next;
      free(tmp);
      tmp = tmp2;
    }
  free(root);
}

t_list		*new_sudoku(t_square *sudoku, int size)
{
  t_list	*list;

  if (!(list = create_list_list(size)))
    return (NULL);
  initialize_list(sudoku->tab, list, size);
  return (list);
}

void		initialize_list(char **tab, t_list *root, int size)
{
  int		i;
  t_list	*tmp;

  i = 0;
  tmp = root->next;
  while (i < 81 && tmp && tmp != root)
    {
      if (tab[i / 9][i % 9] != ' ')
	tmp->value = tab[i / 9][i % 9] - 48;
      tmp = tmp->next;
      i = i + 1;
    }
 }

t_list		*create_list_list(int size)
{
  int			i;
  t_list		*root;

  i = 0;
  if (!(root = malloc(sizeof(t_list))))
    return (NULL);
  root->next = root;
  root->prev = root;
  while (i < size)
    {
      if (add_one_list_to_root(root, i))
	return (NULL);
      i += 1;
    }
  return (root);
}

int		add_one_list_to_root(t_list *root, int position)
{
  t_list	*elem;

  if (!(elem = malloc(sizeof(t_list))))
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
