#include "pacine_lib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	putnbr_helper(int long number)
{
	if (number)
	{
		putnbr_helper(number / 10);
		ft_putchar(number % 10 + 48);
	}
}

void	ft_putnbr(int nb)
{
	long int	number;

	number = nb;
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
	}
	if (number == 0)
	{
		ft_putchar((char)(48));
	}
	putnbr_helper(number);
}

int	ft_atoi(char *str)
{
	int	result;
	int	iter;
	int	signe;

	iter = 0;
	result = 0;
	signe = 1;
	while (((str[iter] <= 32  && str[iter] > 5 ) || str[iter] == '+' ) &&
			str[iter] != '\0')
	{
		iter++;
	}
	if (str[iter] == '-')
	{
		signe = -1;
		iter++;
	}
	while (str[iter] != '\0' && str[iter] >= '0' &&
			str[iter] <= '9')
	{
		result = result * 10 + (str[iter] - 48);
	}
	return (signe * result);
}

void	print_table(char **table, int n, int m)
{
	int	i;
	int	j;

	i = 0;
	ft_putchar('\n');
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			ft_putchar(table[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}

}
