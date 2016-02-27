/*
** free.c for sudoki.c in /home/brout_m/RENDU/CPE/sudoki-bi/generate
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 20:54:54 2016 marc brout
** Last update Sat Feb 27 21:01:45 2016 marc brout
*/

#include <stdlib.h>
#include "generate.h"

void		free_tab(int	**tab)
{
  free(tab[0]);
  free(tab[1]);
  free(tab);
}

void		free_square(t_square *root)
{
  t_square	*tmp;
  t_square	*tmp2;

  tmp = root->next;
  while (tmp && tmp != root)
    {
      tmp2 = tmp->next;
      free_tab(tmp->avail);
      free(tmp);
      tmp = tmp2;
    }
  free(root);
}
