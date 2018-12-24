#include "expert.h"

void	ft_undefined(t_g *all)
{
	//accessing random memory if no undefined items
	int i, j;
	char *res;

	i = 0;
	j = 0;

	all->undefc = 0;
	while (all->results[i])
	{
		res = ft_strchr(all->facts, all->results[i]);
		if (res == NULL)
		{
			all->undefined = ft_strnew(all->undefc + 1);
			all->undefined[all->undefc] = all->results[i];
			all->undefc += 1;
		}
		i++;
	}
}
