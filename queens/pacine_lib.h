#ifndef PACINE_LIB_H
# define PACINE_LIB_H
# include <unistd.h>
# define True 1
# define False 0

# include <unistd.h>
# include <stdlib.h>
typedef int	t_bool;
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int	ft_atoi(char *str);
int	check_error(char **sudoku);
int	solvers(char sudoku[8][8], int *prob, int column, int *poss);
void	create_table(char table[8][8], int row, int column);
void	print_table(char sudoku[8][8], int n , int m);
#endif
