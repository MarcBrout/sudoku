/*
** res.h for res in /home/duhieu_b/Prog_elem/sudoki-bi/include
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Feb 27 11:57:09 2016 benjamin duhieu
** Last update Sat Feb 27 23:57:56 2016 benjamin duhieu
*/

#ifndef RES_H_
# define RES_H_

typedef	struct	s_position
{
  int		x;
  int		y;
}		t_position;

typedef	struct	s_case
{
  t_position	pos;
  int		*tab;
  struct s_case	*next;
  struct s_case	*prev;
}		t_case;

/*
** check functions to find if the number is in the "grille" : resol.c
*/

int	chk_all(t_case *, char **, int);
int	chk_box(char **, t_case *, int);
int	chk_column(char **,t_case *, int);
int	chk_line(char **, t_case *, int);
int	put_in_tab(t_case *, t_case *, char **);

/*
** check the tab where we find a random number to fill the "grille": fill_tab.c
*/

int	check_tab(int *);
int	choose_nbr(t_case *);

/*
** tab & list : case_list.c
*/

int	add_in_list(int, int, t_case *);
t_case *put_in_list(t_case *, char **);

/*
** check the tab to define the rank of the future list: check.c
*/

int	*box(char **, int, int, int *);
int	*column(char **, int, int *);
int	*line(char **, int, int *);
int	count_possib(int *);
int	check(char **, int, int, int *);

/*
** begin_list && put an order : order.c
*/

int	nb_possib(char **);
int	res(char **);
void	init_tab(int *);
void	road_to_list(t_sudoku *);

/*
** free : free_back.c
*/

void	free_backtracing(t_case *);

/*
** error : error.c
*/

int	my_puterror(const char *);
int	my_strlen(const char *);

#endif /* !RES_H_ */
