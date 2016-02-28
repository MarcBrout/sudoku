/*
** tab_and_list.c for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 00:58:19 2016 marc brout
** Last update Sun Feb 28 00:06:02 2016 marc brout
*/

#include <stdlib.h>
#include "sudoki.h"

void		add_to_end_list(t_sudoku *first, t_sudoku *last)
{
  t_sudoku	*tmp;

  tmp = first;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = last;
}

char		**set_tab()
{
  char		**tmp;
  int		i;

  if (!(tmp = malloc(sizeof(char *) * 10)))
    return (my_puterrornull(MALLOC_ERROR));
  i = -1;
  while (++i < 9)
    {
      if (!(tmp[i] = malloc(10)))
	return (my_puterrornull(MALLOC_ERROR));
      tmp[i][9] = 0;
    }
  tmp[9] = NULL;
  return (tmp);
}

void		fill_line(char *dest, const char *src)
{
  int		i;
  int		j;

  i = 0;
  j = -1;
  while (++i < 21)
    {
      if (!(i % 2) && ++j < 9)
	dest[j] = src[i];
    }
}
