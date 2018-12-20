#include "expert.h"

void		sort_info(t_g *all)
{
	t_stmts *stmt_head;
	int fcount;

	fcount = 1;
	stmt_head = all->stmts;
	while (all->stmts->next)
	{
		if (all->stmts->stmt[0] == '=')
		{
			all->facts = ft_strsplit(all->stmts->stmt, '=')[0];
			while (all->facts[fcount])
				fcount++;
			all->fcount = fcount;
			ft_putstr("all->facts: ");
			ft_putendl(all->facts);
			ft_putstr("all->fcount: ");
			ft_putnbr(all->fcount);
			ft_putchar('\n');

		} else if (all->stmts->stmt[0] == '?') {
			all->find = ft_strsplit(all->stmts->stmt, '?')[0];
			ft_putstr("all->find: ");
			ft_putendl(all->find);
		} else if (all->stmts->stmt[0] == '#') {
			//	ft_putendl("this is a comment");
		} else {
			all->stmts->data = ft_strchr(all->stmts->stmt, '=');
			if (all->stmts->data != NULL)
			{
				all->stmts->data = ft_strsplit(all->stmts->stmt, '=')[0];
				//ft_putstr("all->stmts->data: ");
				//ft_putendl(all->stmts->data);
				all->stmts->decision = ft_strsplit(all->stmts->stmt, '>')[1];
				//ft_putstr("all->stmts->decision: ");
				//ft_putendl(all->stmts->decision);
			}
		}
		all->stmts = all->stmts->next;
	}
	all->stmts = stmt_head;
	ft_putendl("info sorted successfully");
}

