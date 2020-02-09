#include "pacine_lib.h"
#include <stdio.h>
int	check_dir(int dir)
{
	if (dir < 3)
	{
		return (0);
	}
	else if (dir < 6)
	{
		return (3);
	}
	else if (dir < 9)
	{
		return (6);
	}
	return (-1);
}

void	check_pair(int *pair, int column, int row)
{
	pair[0] = check_dir(row);
	pair[1] = check_dir(column);
}

int	check_box(char **sudoku, int row, int column)
{
	int	tuple[2];
	int	i;
	int	j;

	check_pair(tuple, column, row);
	i = tuple[0];
	while (i < tuple[0] + 3)
	{
		j = tuple[1];
		while (j < tuple[1] + 3)
		{
			if (!(row == i && column == j))
			{
				if (sudoku[i][j] == sudoku[row][column])
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_column(char **sudoku, int row, int column)
{
	int	col;

	col = 0;
	while (col < 9)
	{
		if (col != column)
		{
			if (sudoku[row][col] == sudoku[row][column])
			{
				return (0);
			}
		}
		col++;
	}
	return (1);
}

int	check_row(char **sudoku, int column, int row)
{
	int	r;

	r = 0;
	while (r < 9)
	{
		if (r != row)
		{
			if (sudoku[r][column] == sudoku[row][column])
			{
				return (0);
			}
		}
		r++;
	}
	return (1);
}

int	check_error(char **sudoku)
{
	int	i;
	int	iter;

	i = 0;
	while (i < 9)
	{
		iter = 0;
		while (sudoku[i][iter])
		{
			iter++;
		}
		if (iter < 9)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	get_position(char **sudoku, int *pair)
{
	int	row;
	int	column;

	row = 0;
	while (row < 9)
	{
		column = 0;
		while (column < 9)
		{
			if (sudoku[row][column] == '.')
			{
				pair[0] = row;
				pair[1] = column;
				return;	
			}
			column++;
		}
		row++;
	}
	pair[0] = -1;
	pair[1] = -1;
}

int	solvers(char **sudoku)
{
	int	tuple[2];
	int	occur;
	occur = '1';
	get_position(sudoku, tuple);
	if (tuple[0] == -1)
	{
		return (1);
	}
	while (occur <= '9')
	{
		sudoku[tuple[0]][tuple[1]] = occur;
		if (check_box(sudoku,tuple[0], tuple[1]) && check_column(sudoku, tuple[0], tuple[1])
				&& check_row(sudoku, tuple[1], tuple[0]))
		{
			if (solvers(sudoku))
			{
				return (1);
			}
		}
		occur++;
	}
	sudoku[tuple[0]][tuple[1]] = '.';
	return (0);
}
