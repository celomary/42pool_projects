#include <stdio.h>

int	match(char *str, char *pattern)
{
	int	i;
	int	j;
	while (*pattern == '*')
		pattern++;
	if (*pattern == '\0')
		return (1);
	j = 0;
	while (str[j] != '\0')
	{
		i = 0;
		while (str[j] == pattern[i] && str[j] != '\0')
		{
			j++;
			i++;
		}
		if (str[j] == '\0' && pattern[i] == '\0')
		{
			return (1);
		}
		if (pattern[i] == '*')
			return (match((str + j), (pattern + i)));
		j++;
	}
	return (0);
}
