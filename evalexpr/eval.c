#include "eval_exp.h"

void			push(struct s_stack **st, char *data)
{
	struct s_stack	*new;

	new = (struct s_stack *)malloc(sizeof(struct s_stack));
	new->next = *st;
	new->str  = data;
	(*st) = new;
}

void			init_str(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

struct s_stack		*pop(struct s_stack **st)
{
	struct s_stack	*old;

	old = NULL;
	if (*st)
	{
		old = *st;
		*st = old->next;
	}
	return (old);
}

int			ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while ( *str != '\0' && (*str) >= '0' && (*str) <= '9')
	{
		result = result * 10 + ((*str) - 48);
		str++;
	}
	return (sign * result);
}

void		itoa_helper(int nbr, char *str, int  i, int is_negative)
{
	if (nbr != 0)
	{
		itoa_helper(nbr / 10, str, i + 1, is_negative);
		str[i] = ((nbr % 10) + 48);
	}
	else
	{
		if (is_negative)
			str[i] = '-';
	}
}

void		reverse_str(char *str)
{
	int	len;
	int	i;
	char	k;

	len = 0;
	while (str[len + 1] != '\0')
		len++;
	i = 0;
	while (i < len)
	{
		k = str[len];
		str[len] = str[i];
		str[i] = k;
		i++;
		len--;
	}
}

char		*ft_itoa(int nbr)
{
	char	*str;

	str = (char *)malloc(5);
	init_str(str, 5);
	if (nbr == 0)
	       str[0] = '0';
	if (nbr < 0)
		itoa_helper(-1 * nbr, str, 0, 1);
	else
		itoa_helper(nbr, str, 0, 0);
	reverse_str(str);
	return (str);	
}

int			priority(char c)
{
	if (c == '(')
		return (4);
	if (c == '*' || c == '/')
		return (2);
	if (c == '+' || c == '-')
		return (1);
	if (c == '^')
		return (3);
	return (0);
}

void			add(struct s_stack **st, char *str, int *iter, int (*range)(char c))
{
	int	i;
	int	j;
	char	*arr;

	i = 0;
	j = *iter;
	if (range(str[j]) && str[j] != '\0')
	{
		arr = (char *)malloc(5);
		init_str(arr, 5);
		while (range(str[j]))
		{
			arr[i] = str[j];
			i++;
			j++;
		}
		*iter = j;
		push(st, arr);
	}
}

int			number_range(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			operator_range(char c)
{
	if (!number_range(c) && c != ' ')
		return (1);
 	return (0);
}

void			post_fix_end(struct s_stack **oper, struct s_stack **numbers)
{
	struct s_stack	*st;

	st = pop(oper);
	if (st)
	{
		post_fix_end(oper, numbers);
		push(numbers, st->str);
	}
}

void			result_eval(char *str, struct s_stack **numbers, struct s_stack **oper, int j)
{
	char	*arr;

	while (str[j] != '\0')
	{
		while (str[j] == ' ')
			j++;
		add(numbers, str, &j, &number_range);
		if (operator_range(str[j]) && *oper)
		{
			arr = pop(oper)->str;
			if (arr[0] == ')')
			{
				arr = pop(oper)->str;
				while (arr[0] != '(')
				{
					push(numbers, arr);
					arr = pop(oper)->str;
				}
				continue;
			}
			else if (priority(arr[0]) >= priority(str[j]) && arr[0] != '(')
			{
				push(numbers, arr);
				continue;
			}
			else if (priority(arr[0]) < priority(str[j]) || arr[0] == '(')
			{
				push(oper, arr);
			}
		}

		add(oper, str, &j, &operator_range);
	}
	post_fix_end(oper, numbers);
}

void			display(struct s_stack *st)
{
	while (st)
	{
		printf("%s",st->str);
		st = st->next;
	}
	printf("\n");
}

char			*express(char *exp)
{
	int	it;
	int	len;
	char	*str;

	it = 0;
	while (exp[it] != '\0')
		it++;
	str = (char *)malloc(sizeof(char) * (it + 10));
	str[0] = exp[0];
	it = 1;
	len = 1;
	while (exp[it] != '\0')
	{
		if (operator_range(exp[it]) && operator_range(str[len]))
		{
			str[len] = ' ';
			len++;
		}
		str[len] = exp[it];
		len++;
		it++;

	}
	str[len] = ' ';
	str[++len] = '\0';
	return (str);
}
