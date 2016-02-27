/*
** free.c for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 01:15:39 2016 marc brout
** Last update Sat Feb 27 01:30:05 2016 marc brout
*/

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

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
