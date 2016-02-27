/*
** main.c for main in /home/duhieu_b/Prog_elem/sudoki-bi/main
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Feb 27 11:00:52 2016 benjamin duhieu
** Last update Sat Feb 27 12:59:17 2016 benjamin duhieu
*/

#include "sudoki.h"

int		main()
{
  t_sudoku	*tmp;

  tmp = NULL;
  if (!(tmp = parse_input()))
    return (1);
  print_sudoki_list(tmp);
  road_to_list(tmp);
  print_sudoki_list(tmp);
  free_sudoku(tmp);
  return (0);
}
