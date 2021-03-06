#include "expert.h"

void		sort_info(t_g *all)
{
	t_stmts *stmt_head;
	int fcount, findc;

	fcount = 1;
	findc = 1;
	stmt_head = all->stmts;
	while (all->stmts->next)
	{
		if (all->stmts->stmt[0] == '=')
		{
			if (ft_isalpha(all->stmts->stmt[1]) == 1)
			{
				all->facts = ft_strsplit(all->stmts->stmt, '=')[0];
				while (all->facts[fcount])
					fcount++;
				all->fcount = fcount;
			} else {
				ft_putendl("no facts provided...");
				all->facts = ft_strdup(" ");
			}

		} else if (all->stmts->stmt[0] == '?') {
			all->find = ft_strsplit(all->stmts->stmt, '?')[0];
			while (all->find[findc])
				findc++;
			all->results = ft_strsplit(all->stmts->stmt, '?')[0];
			all->findc = findc;
		} 
		/* comments are now being removed in read_file
		else if (all->stmts->stmt[0] == '#') {
				ft_putendl("this is a comment");
		}
	       */	
		else {
			all->stmts->data = ft_strchr(all->stmts->stmt, '=');
			if (all->stmts->data != NULL)
			{
				all->stmts->data = ft_strsplit(all->stmts->stmt, '=')[0];
				//	ft_putstr("Data: ");
				//	ft_putendl(all->stmts->data);
				all->stmts->decision = ft_strsplit(all->stmts->stmt, '>')[1];
				//	ft_putstr("Decision: ");
				//	ft_putendl(all->stmts->decision);
			}
		}
		all->stmts = all->stmts->next;
	}
	all->stmts = stmt_head;
	ft_putendl("info sorted successfully");
}

