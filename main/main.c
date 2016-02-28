/*
** main.c for main in /home/duhieu_b/Prog_elem/sudoki-bi/main
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Feb 27 11:00:52 2016 benjamin duhieu
** Last update Sun Feb 28 12:06:02 2016 benjamin duhieu
*/

#include "sudoki.h"

int		main(int argc, char **argv)
{
  t_sudoku	*tmp;

  if (argc > 1 || !argv)
    return (my_puterror
	    ("Usage : ./sudoki-bi use a valid map on the standard input (0).\n"));
  tmp = NULL;
  if (!(tmp = parse_input()))
    return (1);
  road_to_list(tmp);
  print_sudoki_list(tmp);
  free_sudoku(tmp);
  return (0);
}
