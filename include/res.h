/*
** res.h for res in /home/duhieu_b/Prog_elem/sudoki-bi/res
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Feb 26 21:59:24 2016 benjamin duhieu
** Last update Sat Feb 27 01:40:48 2016 benjamin duhieu
*/

#ifndef RES_H_
# define RES_H_

typedef	struct	s_position
{
  int		x;
  int		y;
}		t_position;

typedef struct	s_case
{
  t_position	pos;
  char		count;
  struct s_case	*next;
  struct s_case	*prev;
}		t_case;

int	add_in_list(int, int, t_case *);
int	check(char **; int, int);
int	check_box(char **, t_case *);
int	check_column(char **, t_case *);
int	check_line(char **, t_case *);
int	put_in_tab(t_case *, char **);
int	res(char **);
void	nb_possib(char **);
t_case	*put_in_list(t_case *, char **);


# endif /* !RES_H_ */
