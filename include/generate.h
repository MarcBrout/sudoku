/*
** generate.h for sudoku
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Feb 27 12:18:46 2016 marc brout
** Last update Sat Feb 27 17:13:17 2016 marc brout
*/

#ifndef GENERATE_H_
# define GENERATE_H_

# define LINE 2
# define COLOMN 9

typedef struct		s_square
{
  int			**avail;
  int			position;
  int			x;
  int			y;
  int			cube;
  int			value;
  struct s_square	*next;
  struct s_square	*prev;
}			t_square;

t_square	*create_square_list(int size);
int		add_one_square_to_root(t_square *root, int position);
void		set_tab_cell_to_nb(int **tab, int cell, int nb);
void		set_tab_int(int **tab, int nb);
int		count_available_nb(int **tab);
int		rand_nb(t_square *square);
int		compare_squares(t_square *square,
				t_square *test,
				int value);
int		check_existant(int i,
			       t_square *root,
			       t_square *square,
			       int value);
int		resolve_square(int i,
			       t_square *root,
			       t_square *square);
void		reset_square(t_square *square);
void		fill_list(t_square *root, int size);
void		show_tab_int(t_square *root, int size, int difficulty);

#endif /* !GENERATE_H_ */
