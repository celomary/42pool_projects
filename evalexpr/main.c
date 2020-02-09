#include "eval_exp.h"

int	main(int argc , char **argv)
{
	if (argc == 2)
		eval_expression(argv[1]);
	else
		printf("program accept one argument!\n");
	return (0);
}
