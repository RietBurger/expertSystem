#include "expert.h"

char		ft_match(char *temp, t_g *all)
{
	int j, fmax, fpos;

	fmax = all->fcount;
	fpos = 0;
	while (fpos <= fmax)
	{
		//ft_putstr("this is all->facts[fpos] in ft_match: ");
		//ft_putchar(all->facts[fpos]);
		//ft_putchar('\n');
		j = 0;
		while (temp[j] == ' ')
			j++;

		if (temp[j] == all->facts[fpos])
		{
			return ('t');
		}
		fpos++;
	}
	return ('f');
}

char		ft_match_chr(char temp, t_g *all)
{
	int fmax, fpos;

	fmax = all->fcount;
	fpos = 0;
	while (fpos <= fmax)
	{
		if (temp == all->facts[fpos])
		{
			return ('t');
		}
		fpos++;
	}
	return ('f');
}
