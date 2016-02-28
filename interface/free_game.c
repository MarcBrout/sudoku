/*
** free_game.c for free in /home/duhieu_b/Prog_elem/sudoki-bi/interface
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 12:17:49 2016 benjamin duhieu
** Last update Sun Feb 28 13:01:12 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "sudoki.h"

void		freestr(char *str)
{
  if (str)
    free(str);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (i < 9)
    {
      free(tab[i]);
      i += 1;
    }
  free(tab);
}

void		free_sudoku(t_sudoku *sudo)
{
  t_sudoku	*tmp;
  t_sudoku	*tmp2;

  tmp = sudo->next;
  while (tmp)
    {
      tmp2 = tmp->next;
      free_tab(tmp->tab);
      free(tmp);
      tmp = tmp2;
    }
  free(sudo);
}
