/*
** compare.c for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun Feb 28 19:57:39 2016 marc brout
** Last update Sun Feb 28 21:00:20 2016 marc brout
*/

#include	"game.h"
#include	<stdio.h>

void		reset_grid(t_list *root)
{
  t_list	*curser;

  curser = root->next;
  while (curser && curser != root)
    {
      if (!curser->lock)
	curser->value = 0;
      curser = curser->next;
    }
}

int		compare_lists(t_list *list, t_list *test)
{
  if (list->x == test->x && list->value == test->value)
    return (1);
  if (list->y == test->y && list->value == test->value)
    return (1);
  if (list->cube == test->cube && list->value == test->value)
    return (1);
  return (0);
}

int		check_existant(t_list *root, t_list *list)
{
  t_list	*curser;

  curser = root->next;
  while (curser && curser != root)
    {
      if (!list->value || compare_lists(curser, list))
	return (1);
      curser = curser->next;
    }
  return (0);
}

void		check_whole_grid(t_main *data, t_list *root)
{
  t_list	*curser;

  curser = root->next;
  while (curser && curser != root)
    {
      if (check_existant(root, curser))
	data->lose = 1;
      curser = curser->next;
    }
  if (!data->lose)
    data->vic = 1;
  printf("vic = %d, lose = %d\n", data->vic, data->lose);
}
