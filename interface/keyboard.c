/*
** keyboard.c for sudoku in /home/brout_m/RENDU/CPE/sudoki-bi/interface
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun Feb 28 14:28:25 2016 marc brout
** Last update Sun Feb 28 16:32:52 2016 marc brout
*/

#include "sudoki.h"

t_bunny_response	keyboard(t_bunny_event_state state,
				 t_bunny_keysym keysym,
				 void *data)
{
  t_main		*sudoki;

  sudoki = (t_main *)data;
  if (keysym == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  if (keysym
  return (GO_ON);
}
