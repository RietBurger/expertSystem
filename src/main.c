#include "expert.h"


void	ft_init_ints(t_g *all)
{
	all->possible_vars = 0;
	all->fcount = 0;
	all->resultsc = 0;
	all->findc = 0;
	all->fcount = 0;
	all->undefc = 0;
}

int		main(void)
{
	t_g all;
	t_stmts *head;

	int i, j;

	i = j = 0;

	head = NULL;
	all.stmts = NULL; 
	ft_putendl("starting main");
	all.stmts = read_file(&all);
	ft_init_ints(&all);
	//ft_putendl("starting sort_info");
	//sort_info(&all);
	/*
	head = all.stmts;
	ft_putendl("now printing all.stmts->stmts");
	while (all.stmts->next)
	{
		ft_putstr("all.stmts->stmt: ");
		ft_putendl(all.stmts->stmt);
		all.stmts = all.stmts->next;
	}
	all.stmts = head;
	*/
	ft_putendl("starting sort_info");
	sort_info(&all);
	ft_find(&all);
	ft_find(&all);
	ft_undefined(&all);
	ft_main_output(&all);

	free_stmts(all.stmts);
	return (0);
}
