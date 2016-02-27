/*
** check.c for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi/generate
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 20:52:31 2016 marc brout
** Last update Sat Feb 27 21:04:13 2016 marc brout
*/

#include "generate.h"

int		compare_squares(t_square *square, t_square *test, int value)
{
  if (square->x == test->x && square->value == value)
    return (1);
  if (square->y == test->y && square->value == value)
    return (1);
  if (square->cube == test->cube && square->value == value)
    return (1);
  return (0);
}

int		check_existant(int i, t_square *root,
			       t_square *square, int value)
{
  int		cur;
  t_square	*curser;

  curser = root->next;
  cur = 0;
  while (curser && curser != root && cur < i)
    {
      if (compare_squares(curser, square, value))
	return (1);
      curser = curser->next;
    }
  return (0);
}