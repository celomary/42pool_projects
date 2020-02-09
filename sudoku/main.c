#include "pacine_lib.h"
#include <stdio.h>
#include <stdlib.h>

char	**copy_table(char **argv)
{
	char **table;
	int	i;
	int	j;

	i = 1;
	table = (char **)malloc(sizeof(char *) * 9);
	while (i < 10)
	{
		j = 0;
		table[i - 1] = (char *)malloc(sizeof(char) * 9);
		while (j < 9)
		{
			table[i - 1][j] = argv[i][j];
			j++;
		}
		i++;
	}
	return (table);
}
int main(int argc, char **argv)
{
	char	**new;
	if (argc == 10)
	{
		new = copy_table(argv);
		print_table(new, 9, 9);
		solvers(new);
		print_table(new, 9,9);

	}
	return (0);
}
