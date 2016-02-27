/*
** free.c for free in /home/duhieu_b/Prog_elem/sudoki-bi/res
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Feb 27 11:24:58 2016 benjamin duhieu
** Last update Sat Feb 27 11:28:48 2016 benjamin duhieu
*/

#include "sudoki.h"

void		free_backtracing(t_case *root)
{
  t_case	*elem;

  elem = root->next;
  while (elem != root)
    {
      elem = elem->next;
      free(elem->prev);
    }
  free(elem);
}
