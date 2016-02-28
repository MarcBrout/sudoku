/*
** parser.h for sudoki in /home/brout_m/RENDU/CPE/sudoki-bi/include
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 23:08:11 2016 marc brout
** Last update Sun Feb 28 19:13:36 2016 marc brout
*/

#ifndef PARSER_H_
# define PARSER_H_

# define MAP_ERROR "MAP ERROR\n"
# define MALLOC_ERROR "Memory allocation error, program exited.\n"

# ifndef INTERFACE
#  define INTERFACE

typedef struct		s_list
{
  int			position;
  int			x;
  int			y;
  int			cube;
  int			value;
  int			lock;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

# endif /* !INTERFACE */

typedef struct		s_sudoku
{
  int			valid;
  char			**tab;
  t_list		*squares;
  t_list		*cursquare;
  struct s_sudoku	*next;
}			t_sudoku;

/*
** check functions : check.c
*/

void	is_it_valid(t_sudoku *sudo);
void	check_integrity(t_sudoku *sudo);
int	check_colomn(t_sudoku *sudo, int x, int y, int k);
int	check_line(t_sudoku *sudo, int x, int y, int k);
int	check_cube(t_sudoku *sudo, int x, int y, int k);

/*
** show tabs : show.c
*/

void	*my_puterrornull(const char *str);
void	show_valid_sudo(t_sudoku *sudos);
void	show_not_valid_sudo(t_sudoku *sudos);
void	print_sudoki_list(t_sudoku *sudos);

/*
** tab & list : tab_and_list.c
*/

char	**set_tab();
void	add_to_end_list(t_sudoku *first, t_sudoku *last);
void	fill_line(char *dest, const char *src);

/*
** parsing file : parsing.c
*/

int	check_str(const char *);
int	parse_tab(t_sudoku *sudo);
t_sudoku *parse_one_imput();
t_sudoku *parse_input();

/*
** free : free.c
*/

void	freestr(char *str);
void	free_tab(char **tab);
void	free_sudoku(t_sudoku *sudo);

#endif /* !PARSER_H_ */
