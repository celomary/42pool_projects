# include "eval_exp.h"

int	zero_division_error(char *expr)
{
	int	iter;
	int	j;

	iter = 0;
	while (expr[iter + 1] != '\0')
	{
		if (expr[iter] == '/')
		{
			j = iter + 1;
			while (expr[j] == ' ' && expr[j] != '\0')
				j++;
			if (expr[j] == '0')
				return (1);
		}
		iter++;
	}
	return (0);
}

void	push_error(struct s_error **st, char data)
{
	struct	s_error *new;

	new = (struct s_error *)malloc(sizeof(struct s_error));
	new->next = *st;
	new->para = data;
	*st = new;
}

void	pop_error(struct s_error **st)
{
	struct s_error *old;

	old = *st;
	*st = old->next;
	free(old);
}

int	check_parenth(char *expr)
{
	int		i;
	struct s_error *error;

	error = NULL;	
	i = 0;
	while (expr[i] != '\0')
	{
		if (expr[i] == '(')
			push_error(&error, '(');
		if (expr[i] == ')')
		{
			if (!error || error->para != '(')
				return (1);
			else
				pop_error(&error);
		}
		i++;
	}
	if (error)
		return (1);
	return (0);
}

int	in_allowed_oper(char c)
{
	char	oper[] = "+-/*^";
	int	i;

	i = 0;
	while (oper[i] != '\0')
	{
		if (oper[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_syntax(char *expr, int iter, int oper, int number)
{
	int	locked;

	locked = 1;
	while (expr[iter] != '\0')
	{
		if (in_allowed_oper(expr[iter]))
		{
			oper++;
			number = 0;
			locked = 1;
		}
		if (oper > 1)
			return (1);
		if (expr[iter] >= '0' && expr[iter] <= '9')
		{
			oper = 0;
			if (locked)
			{
				number++;
				locked = 0;
			}
		}
		if (number > 1)
			return (1);
		if (expr[iter] == ' ' || expr[iter] == '(' || expr[iter] == ')')
			locked = 1;
		iter++;
	}
	return (0);
}

int	errors(char *expr)
{
	if (zero_division_error(expr))
	{
		printf("zero division error!\n");
		return (1);
	}
	else if (check_parenth(expr) || check_syntax(expr, 0, 0, 0))
	{
		printf("Error syntax!\n");
		return (1);
	}
	return (0);
}
