#include "expert.h"

int		main(void)
{
	t_g all;

	all.stmts = NULL; 
	all.stmts = read_file(&all);

	all.find = save_find(&all);
	all.given = save_given(&all);
	all.values = save_values(&all);
//	all.find = save_vals(&all);	
/*
		while (all.stmts->next)
		{
			ft_putendl(all.stmts->stmt);

			//ft_putendl(all.find->valF); 
			//ft_putendl(all.values->val); 
			ft_putchar('\n');
			all.stmts = all.stmts->next; 
		}
		*/
		free_stmts(all.stmts);
	 //free_all(all.stmts, all.data); 
	return (0);
}
