#ifndef PACINE_LIB_H
# define PACINE_LIB_H
# include <unistd.h>
# define True 1
# define False 0

#include <unistd.h>
typedef int	t_bool;
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int	ft_atoi(char *str);
int	check_error(char **sudoku);
int	solvers(char **sudoku);
void	print_table(char **sudoku, int n , int m);
#endif
