#include "eval_exp.h"

struct s_stack	*reverse_stack(struct s_stack *st)
{
	struct s_stack *stack;

	stack  = NULL;
	while (st)
	{
		push(&stack, st->str);
		st = st->next;
	}
	return (stack);
}

int	power(int num1, int e)
{
	int	result;

	if (e == 0)
		return (1);
	result = 1;
	while (e > 0)
	{
		result *= num1;
		e--;
	}
	return (result);
}
int	operation(int num1, int num2, char oper)
{
	if (oper == '+')
		return (num1 + num2);
	if (oper == '-')
		return (num1 - num2);
	if (oper == '*')
		return (num1 * num2);
	if (oper == '/')
		return (num1 / num2);
	if (oper == '^')
		return (power(num1, num2));
	return (0);
}

int	result (char *expr, struct s_stack *numbers, struct s_stack *oper)
{
	struct s_stack	*new;
	struct s_stack	*st;
	char		*num1;
	char		*num2;
	int		op;

	result_eval(expr, &numbers, &oper, 0);
	numbers = reverse_stack(numbers);
	new = NULL;
	st = pop(&numbers);
	while (st)
	{
		while (number_range((st->str)[0]))
		{
			push(&new, st->str);
			st = pop(&numbers);
		}
		num2 = pop(&new)->str;
		num1 = pop(&new)->str;
		op = operation(ft_atoi(num1), ft_atoi(num2), (st->str)[0]);
		push(&new,ft_itoa(op));
		st = pop(&numbers);
	}
	return (ft_atoi(pop(&new)->str));
}

void	eval_expression(char *expr_)
{
	int	r;

	if (!errors(expr_))
	{
		r = result(express(expr_), NULL, NULL);
		printf("result = %d\n", r);
	}
}
