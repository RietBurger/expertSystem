#include "expert.h"

int		main(void)
{
	t_g all;
	int i, j;

	i = j = 0;

	all.stmts = NULL; 
	ft_putendl("starting main");
	all.stmts = read_file(&all);
	sort_info(&all);
	ft_find(&all);
//	ft_undefined(&all);

	ft_putendl("FINAL RESULTS REQUESTED: ");
	while (all.results[i])
	{
		j = 0;
		while (all.facts[j])
		{
			if (all.results[i] == all.facts[j])
			{
				ft_putchar(all.results[i]);
				ft_putendl(": TRUE");
			}
			j++;
		}
		i++;
	}
	ft_putendl(all.facts);
	ft_putendl(all.results);
//	ft_putendl(all.undefined);

	free_stmts(all.stmts);
	return (0);
}
