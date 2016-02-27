/*
** show.c for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 00:54:57 2016 marc brout
** Last update Sat Feb 27 22:34:24 2016 marc brout
*/

#include <stdio.h>
#include "parser.h"

void		show_valid_sudo(t_sudoku *sudos)
{
  int		y;
  int		x;

  y = -1;
  printf("|------------------|\n");
  while (++y < 9)
    {
      x = -1;
      printf("|");
      while (++x < 9)
	printf(" %c", sudos->tab[y][x]);
      printf("|\n");
    }
  printf("|------------------|\n");
  if (sudos->next)
    printf("####################\n");
}

void		show_not_valid_sudo(t_sudoku *sudos)
{
  int		y;

  y = -1;
  printf("|------------------|\n");
  while (++y < 9)
    printf("|XXXXXXXXXXXXXXXXXX|\n");
  printf("|------------------|\n");
  if (sudos->next)
    printf("####################\n");
}

void		print_sudoki_list(t_sudoku *sudos)
{
  t_sudoku	*tmp;

  tmp = sudos->next;
  while (tmp)
    {
      if (tmp->valid)
	show_valid_sudo(tmp);
      else
	show_not_valid_sudo(tmp);
      tmp = tmp->next;
    }
}
