/*
** keyboard.c for sudoku in /home/brout_m/RENDU/CPE/sudoki-bi/interface
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun Feb 28 14:28:25 2016 marc brout
** Last update Sun Feb 28 17:00:14 2016 marc brout
*/

#include "sudoki.h"

void			move_cur(t_list *root, t_list *cur,
				 int move, int right)
{
  int			i;

  i = -1;
  if (right)
    {
      while (++i < move)
	{
	  if (cur->next == root)
	    cur = cur->next->next;
	  else
	    cur = cur->next;
	}
    }
  else
    {
      while (++i < move)
	{
	  if (cur->prev == root)
	    cur = cur->prev->prev;
	  else
	    cur = cur->prev;
	}
    }
}

void			move_cur_square(t_sudoku *sudoku,
					t_bunny_keysym keysym)
{
  int			i;

  if (keysym == KEY_LEFT)
    move_cur(sudoku->squares, sudoku->cursquare, 1, 1);
  if (keysym == KEY_RIGHT)
    move_cur(sudoku->squares, sudoku->cursquare, 1, 0);
  if (keysym == KEY_UP)
    move_cur(sudoku->squares, sudoku->cursquare, 9, 0);
  if (keysym == KEY_DOWN)
    move_cur(sudoku->squares, sudoku->cursquare, 9, 1);
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
    move_cur_square(sudoku->cursudo, keysym);
  if (state == GO_DOWN && keysym == BKS_N)
    {
      if (sudoki->cursudo->next)
	sudoki->cursudo = sudoki->cursudo->next;
      else
	sudoki->cursudo = sudoki->sudoki->next;
    }
  return (GO_ON);
}
