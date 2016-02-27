/*
** check.c for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi/parsing
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 00:49:25 2016 marc brout
** Last update Sat Feb 27 11:24:13 2016 benjamin duhieu
*/

#include "sudoki.h"

void		is_it_valid(t_sudoku *sudos)
{
  int		y;
  int		x;

  y = -1;
  while (++y < 9)
    {
      x = -1;
      while (++x < 9)
	{
	  if (sudos->tab[y][x] != ' ' &&
	      (sudos->tab[y][x] <= '0' || sudos->tab[y][x] > '9'))
	    sudos->valid = 0;
	}
    }
}

int		check_colomn(t_sudoku *sudo, int x, int y, int k)
{
  int		j;

  j = -1;
  while (++j < 9)
    {
      if (j != y && k != ' ' && sudo->tab[j][x] == k)
	{
	  sudo->valid = 0;
	  return (1);
	}
    }
  return (0);
}

int		check_line(t_sudoku *sudo, int x, int y, int k)
{
  int		i;

  i = -1;
  while (++i < 9)
    {
      if (i != x && k != ' ' && sudo->tab[y][i] == k)
	{
	  sudo->valid = 0;
	  return (1);
	}
    }
  return (0);
}

int		check_cube(t_sudoku *sudo, int x, int y, int k)
{
  int		i;
  int		j;
  int		nbx;
  int		nby;

  nby = 3;
  j = (y / 3) * 3;
  while (--nby >= 0)
    {
      i = (x / 3) * 3;
      nbx = 3;
      while (--nbx >= 0)
	{
	  if (i != x && j != y &&
	      k != ' ' && sudo->tab[j][i] == k && !(sudo->valid = 0))
	    return (1);
	  i++;
	}
      j++;
    }
  return (0);
}

void		check_integrity(t_sudoku *sudo)
{
  int		x;
  int		y;
  int		k;

  y = -1;
  while (++y < 9)
    {
      x = -1;
      while (++x < 9)
	{
	  k = sudo->tab[y][x];
	  if (check_line(sudo, x, y, k) || check_colomn(sudo, x, y, k) ||
	      check_cube(sudo, x, y, k))
	    break;
	}
    }
}
