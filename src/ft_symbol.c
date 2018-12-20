#include "expert.h"

char	ft_symbol(char *str)
{
	char *sym;
	int i;
	char *symfound;

	i = 0;
	sym = "+|";

	while (sym[i])
	{
		symfound = ft_strchr(str, sym[i]);
		if (symfound != NULL)
		{
			return (symfound[0]);
		}
		i++;
	}
	return ('z');
}

