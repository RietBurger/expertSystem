#include "expert.h"


void	ft_main_output(t_g *all)
{
	int i, j, t;
	char A, B;

	A = 't';
	B = 't';

	i = j = 0;

	ft_putendl("FINAL RESULTS REQUESTED: ");
	while (all->results[i])
	{
		j = 0;
		while (all->facts[j])
		{
			if (all->results[i] == all->facts[j])
			{
				ft_putchar(all->results[i]);
				ft_putendl(": TRUE");
				t++;
			}
			j++;
		}
		i++;
	}
/*
	all->resultsc = ft_strlen(all->results);

	ft_putnbr(all->resultsc);
	ft_putchar('\n');
	ft_putnbr(t);
	ft_putchar('\n');
	if (t == all->resultsc)
	{
		ft_putendl("no false results");
	}
	else {
		t = 0;
		while (all->undefined[t])
		{
			ft_putchar(all->undefined[t]);
			ft_putendl(": UNDEFINED");
			t++;
		}
	}
*/

	ft_putstr("all FACTS: ");
	ft_putendl(all->facts);
	ft_putstr("all FIND: ");
	ft_putendl(all->find);
	ft_putstr("all RESULTS: ");
	ft_putendl(all->results);
	ft_putstr("all FALSE: ");
	if (all->undefined != NULL)
		ft_putendl(all->undefined);
	else
		ft_putendl("NONE");

	if(A eqt orsym B eqt)
		ft_putendl("true...");
	else
		ft_putendl("false...");

}
