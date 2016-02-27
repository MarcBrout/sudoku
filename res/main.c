/*
** main.c for main in /home/duhieu_b/Prog_elem/sudoki-bi/res
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Feb 26 22:16:06 2016 benjamin duhieu
** Last update Sat Feb 27 01:43:17 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "res.h"

int	check(char grille[9][9], int i, int j)
{
  int	count;
  int	a;
  int	k;
  int	res;

  res = 0;
  count = 0;
  a = -1;
  while (++count < 9)
    {
      k = -1;
      while (++k < 9)
	{
	  if (k % 3 == 0)
	    a++;
	  if (grille[3 * (i / 3) + a ][3 * (j / 3) + k % 3] == count + 48)
	    res++;
	  else if (grille[i][k] == count + 48)
	    res++;
	  else if (grille[k][j] == count + 48)
	    res++;
	}
    }
  return (res);
}

void	nb_possib(char grille[9][9])
{
  int	i;
  int	j;

  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	{
	  if (grille[i][j] == '0')
	    grille[i][j] = check(grille, i, j);
	}
    }
}

int		add_in_list(int i, int j, t_case *root)
{
  t_case	*elem;

  if ((elem = malloc(sizeof(t_case))) == NULL)
    return (1);
  elem->pos.x = i;
  elem->pos.y = j;
  elem->count = 1;
  elem->next = root;
  elem->prev = root->prev;
  root->prev = elem;
  elem->prev->next = elem;
  return (0);
}

t_case		*put_in_list(t_case *root, char grille[9][9])
{
  int	i;
  int	j;
  int	count;

  count = 0;
  while (++count < 9)
    {
      i = -1;
      while (++i < 9)
	{
	  j = -1;
	  if (grille[i][j] == count)
	    add_in_list(i, j, root);
	}
    }
  return (root);
}

int	check_line(char grille[9][9], t_case *posit)
{
  int	k;

  k = -1;
  while (++k < 9)
    if (grille[posit->pos.x][k] == posit->count + 48)
      return (0);
  return (1);
}

int	check_column(char grille[9][9], t_case *posit)
{
  int	k;

  k = -1;
  while (++k < 9)
    if (grille[k][posit->pos.y] == posit->count + 48)
      return (0);
  return (1);
}

int	check_box(char grille[9][9], t_case *posit)
{
  int	k;
  int	a;

  k = -1;
  a = -1;
  while (++k < 9)
    {
      if (k % 3 == 0)
	a++;
      if (grille[3 * (posit->pos.x / 3) + a ][3 * (posit->pos.y / 3)
					      + k % 3] == posit->count + 48)
	return (0);
    }
  return (1);
}

int		put_in_tab(t_case *posit, char grille[9][9], char c)
{
  if (posit == NULL && c == 0)
    return (0);
  if (posit == NULL && c == 1)
    return (1);
  while (posit->count < 10)
    {
      if ((check_line(grille, posit)) && (check_column(grille)) &&
	  (check_box(grille, posit)))
	{
	  grille[posit->pos.x][posit->pos.y] = posit->count + 48;
	  put_in_tab(posit->next, grille, 0);
	  posit->count++;
	  break ;
	}
      posit->count++;
    }
  if (posit->count == 10)
    {
      grille[posit->pos.x][posit->pos.y] = '0';
      put_in_tab(posit->prev, grille, 1);
      return (1);
    }
  return (0);
}

int		res(char grille[9][9])
{
  t_case	*root;

  if ((root = malloc(sizeof(t_case))) == NULL)
    return (1);
  root = NULL;
  root->next = root;
  root->prev = root;
  nb_possib(grille);
  root = put_in_list(root, grille);
  if (put_in_tab(root, grille, 0))
    return (1);
  return (0);
}

int	main()
{
  char	grille[9][9] = {'0','0','0','0','0','0','0','0','1'
			'0','2','0','1','0','0','9','0','0'
			'0','1','0','0','0','0','2','5','0'
			'0','7','3','0','0','8','0','6','0'
			'1','9','0','0','0','0','7','0','0'
			'8','0','0','0','2','0','0','3','0'
			'0','0','4','0','0','0','0','0','9'
			'0','0','6','5','7','0','0','0','4'
			'3','0','0','8','0','0','1','0','5'};
  if (res(grille))
    return (1);
  return (0);
}
