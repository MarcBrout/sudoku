/*
** parsing.c for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Feb 26 21:10:58 2016 marc brout
** Last update Sat Feb 27 22:45:36 2016 marc brout
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "sudoki.h"

int		check_str(const char *str)
{
  int		i;

  i = -1;
  while (str && str[++i])
    if (str[i] != ' ' && str[i] < '0' && str[i] > '9')
      return (1);
  return (0);
}

int		parse_tab(t_sudoku *sudo)
{
  char		*str;
  int		y;

  y = -1;
  while (++y < 9)
    {
      if (!(str = get_next_line(0)) || strlen(str) < 20)
	return (1);
      fill_line(sudo->tab[y], str);
      if (check_str(sudo->tab[y]))
	return (1);
      freestr(str);
    }
  return (0);
}

t_sudoku	*parse_one_input()
{
  t_sudoku	*sudo;

  if (!(sudo = malloc(sizeof(t_sudoku))))
    return (NULL);
  sudo->valid = 1;
  if (!(sudo->tab = set_tab()))
    return (NULL);
  sudo->next = NULL;
  if (parse_tab(sudo))
    return (NULL);
  return (sudo);
}

t_sudoku	*parse_input()
{
  char		*str;
  t_sudoku	*sudo;
  t_sudoku	*tmp;

  if (!(sudo = malloc(sizeof(t_sudoku))))
    return (NULL);
  sudo->valid = 2;
  sudo->next = NULL;
  while ((str = get_next_line(0)) && strlen(str) < 21 && strlen(str))
    {
      if (!(tmp = parse_one_input()))
	return (NULL);
      freestr(str);
      is_it_valid(tmp);
      check_integrity(tmp);
      add_to_end_list(sudo, tmp);
      if (!(str = get_next_line(0)) || strlen(str) < 20)
	return (NULL);
      freestr(str);
    }
  freestr(str);
  return (sudo);
}
<<<<<<< HEAD

int		main()
{
  t_sudoku	*tmp;

  tmp = NULL;
  if (!(tmp = parse_input()))
    return (1);
  print_sudoki_list(tmp);
  free_sudoku(tmp);
  return (0);
}
=======
>>>>>>> 417913a5c2b1d51d87835da31afd345b3a64c012
