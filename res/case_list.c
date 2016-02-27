/*
** case_list.c for case_list in /home/duhieu_b/Prog_elem/sudoki-bi/res
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Feb 27 11:03:16 2016 benjamin duhieu
** Last update Sat Feb 27 23:29:11 2016 benjamin duhieu
*/

#include <stdlib.h>
#include <stdio.h>
#include "sudoki.h"

int		add_in_list(int i, int j, t_case *root)
{
  t_case	*elem;

  if ((elem = malloc(sizeof(t_case))) == NULL)
    return (my_puterror(MALLOC_ERROR));
  if ((elem->tab = malloc(sizeof(int) * 10)) == NULL)
    return (my_puterror(MALLOC_ERROR));
  elem->tab[9] = -1;
  init_tab(elem->tab);
  elem->pos.x = i;
  elem->pos.y = j;
  elem->next = root;
  elem->prev = root->prev;
  root->prev = elem;
  elem->prev->next = elem;
  return (0);
}

t_case		*put_in_list(t_case *root, char **grille)
{
  int	i;
  int	j;
  int	count;

  count = 0;
  while (++count < 9)
    {
      i = -1;
      while (++i < 9)
	{
	  j = -1;
	  while (++j < 9)
	    if (grille[i][j] == count)
	      add_in_list(i, j, root);
	}
    }
  return (root);
}
