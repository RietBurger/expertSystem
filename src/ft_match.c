#include "expert.h"

char		ft_match(char *temp, t_g *all)
{
	int j, fmax, fpos;

	fmax = all->fcount;
	fpos = 0;
	while (fpos <= fmax)
	{
		j = 0;
		while (temp[j] == ' ')
			j++;
		if (temp[j] == all->facts[fpos])
		{
			ft_putstr("MaTcH on fpos: ");
			ft_putchar(all->facts[fpos]);
			ft_putchar('\n');
			return ('t');
		}
		fpos++;
	}
	return ('f');
}
