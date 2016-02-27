/*
** parser.h for sudoki-bi in /home/brout_m/RENDU/CPE/sudoki-bi/include
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Feb 26 21:13:58 2016 marc brout
** Last update Sat Feb 27 01:22:00 2016 marc brout
*/

#ifndef PARSER_H_
# define PARSER_H_

typedef struct		s_sudoku
{
  int			valid;
  char			**tab;
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

void	show_valid_sudo(t_sudoku *sudos);
void	show_not_valid_sudo(t_sudoku *sudos);
void	print_sudoki_list(t_sudoku *sudos);

/*
** tab & list : tab_and_list.c
*/

void	add_to_end_list(t_sudoku *first, t_sudoku *last);
void	fill_line(char *dest, const char *src);
char	**set_tab();

/*
** free : free.c
*/

void	free_tab(char **tab);
void	free_sudoku(t_sudoku *sudo);

#endif /* !PARSER_H_ */
