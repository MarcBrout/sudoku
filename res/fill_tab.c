/*
** fill_tab.c for fill in /home/duhieu_b/Prog_elem/sudoki-bi/res
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Feb 27 22:39:39 2016 benjamin duhieu
** Last update Sat Feb 27 22:40:45 2016 benjamin duhieu
*/

#include "sudoki.h"

int	check_tab(int *tab)
{
  int	i;

  i = -1;
  while (++i < 9)
    if (tab[i] == 1)
      return (0);
  return (1);
}

int	choose_nbr(t_case *posit)
{
  int	nbr;

  nbr = rand() % 9;
  while (!posit->tab[nbr])
    nbr = rand() % 9;
  posit->tab[nbr] = 0;
  return (nbr + 1);
}
