/*
** free_game.c for free in /home/duhieu_b/Prog_elem/sudoki-bi/interface
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Feb 28 12:17:49 2016 benjamin duhieu
** Last update Sun Feb 28 22:42:11 2016 marc brout
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

void		free_thus_list(t_list *root)
{
  t_list	*tmp;
  t_list	*tmp2;

  tmp = root->next;
  while (tmp != root)
    {
      tmp2 = tmp->next;
      free(tmp);
      tmp = tmp2;
    }
  free(root);
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
      free_thus_list(tmp->squares);
      free(tmp);
      tmp = tmp2;
    }
  free(sudo);
}

void		delete_clip(t_main *sudoki)
{
  int		i;

  bunny_delete_clipable(&(sudoki->pix->clipable));
  bunny_delete_clipable(&(sudoki->nbr.victory->clipable));
  bunny_delete_clipable(&(sudoki->nbr.defeat->clipable));
  bunny_delete_clipable(&(sudoki->nbr.logo->clipable));
  bunny_delete_clipable(&(sudoki->nbr.creator->clipable));
  bunny_delete_clipable(&(sudoki->nbr.inst->clipable));
  i = -1;
  while (++i < 9)
    bunny_delete_clipable(&(sudoki->nbr.number[i]->clipable));
}
