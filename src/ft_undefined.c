#include "expert.h"

void	ft_undefined(t_g *all)
{
	int i;
	char *res;

	i = 0;
	all->undefc = 0;
	while (all->results[i])
	{
		res = ft_strchr(all->facts, all->results[i]);
		if (res == NULL)
		{
			all->undefined[all->undefc] = all->results[i];
			all->undefc += 1;
		}
		i++;
	}
}
