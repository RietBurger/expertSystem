#include "expert.h"

int		main(void)
{
	t_g all;
	int i, j;

	i = j = 0;

	all.stmts = NULL; 
//	ft_putendl("starting main");
	all.stmts = read_file(&all);
	sort_info(&all);
	ft_find(&all);
	ft_find(&all);
	ft_undefined(&all);
	ft_main_output(&all);


	free_stmts(all.stmts);
	return (0);
}
