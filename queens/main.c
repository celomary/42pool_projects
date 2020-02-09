#include "pacine_lib.h"

int	main(void)
{
	int	result;
	char	table[8][8];
	int	poss[8];

	result = 0;
	create_table(table, 8, 8);
	solvers(table, &result, 0, poss);
	ft_putnbr(result);
	ft_putchar('\n');
	return (0);
}
