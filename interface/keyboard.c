/*
** keyboard.c for sudoku in /home/brout_m/RENDU/CPE/sudoki-bi/interface
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun Feb 28 14:28:25 2016 marc brout
** Last update Sun Feb 28 20:54:53 2016 marc brout
*/

#include <stdio.h>
#include "sudoki.h"

t_list			*move_cur(t_list *root, t_list *cur,
				  int move, int right)
{
  int			i;

  i = -1;
  if (!right)
    {
      while ((++i < move || cur->lock) && i < 81)
	{
	  if (cur->next == root)
	    cur = cur->next->next;
	  else
	    cur = cur->next;
	}
    }
  else
    {
      while ((++i < move || cur->lock) && i < 81)
	{
	  if (cur->prev == root)
	    cur = cur->prev->prev;
	  else
	    cur = cur->prev;
	}
    }
  return (cur);
}

void			move_cur_square(t_sudoku *sudoku,
					t_bunny_keysym keysym)
{
  if (keysym == BKS_LEFT)
    sudoku->cursquare = move_cur(sudoku->squares, sudoku->cursquare, 1, 1);
  if (keysym == BKS_RIGHT)
    sudoku->cursquare = move_cur(sudoku->squares, sudoku->cursquare, 1, 0);
  if (keysym == BKS_UP)
    sudoku->cursquare = move_cur(sudoku->squares, sudoku->cursquare, 9, 1);
  if (keysym == BKS_DOWN)
    sudoku->cursquare = move_cur(sudoku->squares, sudoku->cursquare, 9, 0);
}

void			input_number(t_main *data,
				     t_sudoku *sudoku,
				     t_bunny_keysym keysym)
{
  if (keysym >= BKS_0 && keysym <= BKS_9 && !sudoku->cursquare->lock)
    {
      sudoku->cursquare->value = keysym - 26;
      sudoku->cursquare = move_cur(sudoku->squares, sudoku->cursquare, 1, 0);
    }
  if (keysym == BKS_RETURN)
    check_whole_grid(data, sudoku->squares);
  if (keysym == BKS_R)
    {
      reset_grid(sudoku->squares);
      data->vic = 0;
      data->lose = 0;
      sudoku->cursquare = sudoku->squares->next;
    }
}

t_bunny_response	keyboard(t_bunny_event_state state,
				 t_bunny_keysym keysym,
				 void *data)
{
  t_main		*sudoki;

  sudoki = (t_main *)data;
  if (keysym == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN)
    {
      move_cur_square(sudoki->cursudo, keysym);
      input_number(data, sudoki->cursudo, keysym);
    }
  if (state == GO_DOWN && keysym == BKS_N)
    {
      if (sudoki->cursudo->next)
	sudoki->cursudo = sudoki->cursudo->next;
      else
	sudoki->cursudo = sudoki->sudoki->next;
    }
  return (GO_ON);
}
