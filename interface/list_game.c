/*
** list_game.c for gamelist in /home/duhieu_b/Prog_elem/sudoki-bi/interface
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 12:16:37 2016 benjamin duhieu
** Last update Sun Feb 28 13:01:57 2016 benjamin duhieu
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
