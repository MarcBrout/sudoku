/*
** parser.h for sudoki-bi in /home/duhieu_b/Prog_elem/sudoki-bi/include
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Last update Sat Feb 27 22:47:04 2016 marc brout
** Last update Sat Feb 27 12:00:46 2016 benjamin duhieu
*/

#ifndef PARSER_H_
# define PARSER_H_

typedef struct		s_sudoku
{
  int			valid;
  int			block;
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
