#include "pacine_lib.h"

int	check_top_diagonal(char table[8][8], int row, int column)
{
	int	i;

	i = 1;
	while (row - i >= 0 && column - i >= 0)
	{
		if(table[row - i][column - i] == 'o')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_bottom_diagonal(char table[8][8], int row, int column)
{
	int	i;

	i = 1;
	while ( row + i < 8 && column - i >= 0)
	{
		if (table[row + i][column - i] == 'o')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_diagonal(char table[8][8], int row, int column)
{
	return (check_bottom_diagonal(table, row, column) && check_top_diagonal(table, row, column));
}

int	check_column(char table[8][8], int row, int column)
{
	int	i;

	i = 1;
	while (column - i >= 0)
	{
		if (table[row][column - i] == 'o')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_row(char table[8][8], int row , int column)
{
	int	i;

	i = 0;
	while (row + i < 8)
	{
		if (row != i && table[i][column] == 'o')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	create_table(char table[8][8], int rows, int column)
{
	int	iter;
	int	it;

	iter = 0;
	while (iter < rows)
	{
		it = 0;
		while (it < column)
		{
			table[iter][it] = 'x';
			it++;
		}
		iter++;
	}
}

void	last_column(char table[8][8], int column)
{
	int	row;

	row = 0;
	while (row < 8)
	{
		table[row][column]  = 'x';
		row++;
	}
}
void	print_poss(int *poss)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_putnbr(poss[i]);
		i++;
	}
	ft_putchar('\n');
}

int	solvers(char table[8][8], int *prob, int column, int *posibility)
{
	int	row;

	row = 0;
	if (column == 8)
	{
		(*prob)++;
		print_poss(posibility);
		last_column(table, 7);
		return (1);
	}
	while (row < 8)
	{
		posibility[column] = row + 1;
		if (check_column(table, row, column) && check_diagonal(table, row, column) &&
				check_row(table, row, column))
		{
			table[row][column] = 'o';
			solvers(table, prob, column + 1, posibility);
		}
		table[row][column] = 'x';
		row++;
	}
	return (0);
}
