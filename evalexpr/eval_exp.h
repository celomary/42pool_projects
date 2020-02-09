#ifndef EVAL_EXP_H
# define EVAL_EXP_H

# include <stdlib.h>
# include <stdio.h>
struct			s_stack
{
	char		*str;
	struct s_stack	*next;
};

struct			s_error
{
	char		para;
	struct s_error	*next;
};

void			result_eval(char *str, struct s_stack **numbers, struct s_stack	**oper, int j);
void			display(struct s_stack *st);
char			*express(char *exp);
char			*ft_itoa(int nb);
int			ft_atoi(char *str);
struct s_stack		*pop(struct s_stack **st);
void			push(struct s_stack **st, char *data);
int			number_range(char c);
void			eval_expression(char *expr_);
int			errors(char *expr_);
#endif
