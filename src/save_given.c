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

void	ft_find(t_g *all)
{
	t_stmts *head;
	char **splits;
	int i, scount, cnt;
	char split1, split2;

	i = 0;
	cnt = 0;
	head = all->stmts;

	while (cnt < all->fcount)
	{
		while (all->find[i])
		{
			ft_putstr("all->find[");
			ft_putchar(all->find[i]);
			ft_putendl("]");

			while (all->stmts->next && all->stmts->decision)
			{
				if (all->find[i] == all->stmts->decision[1])
				{
					ft_putstr("decision stmt: ");
					ft_putendl(all->stmts->stmt);
					all->stmts->operatorSym = ft_symbol(all->stmts->data);
					splits = ft_strsplit(all->stmts->data, all->stmts->operatorSym);
					scount = 0;
					if (splits != NULL)
					{
						split1 = ft_match(splits[0], all);
						split2 = ft_match(splits[1], all);
						if (all->stmts->operatorSym == '+')
						{
							if (split1 == 't' && split2 == 't') {
								if (ft_strchr(all->facts, all->stmts->decision[1]) == NULL)
								{
									all->facts[all->fcount] = all->stmts->decision[1];
									all->fcount += 1;
									ft_putstr("AND new fact: ");
									ft_putendl(all->facts);
								}
							}
						}
						if (all->stmts->operatorSym == '|')
						{
							if (split1 == 't' || split2 == 't')
							{
								if (ft_strchr(all->facts, all->stmts->decision[1]) == NULL)
								{
									all->facts[all->fcount] = all->stmts->decision[1];
									all->fcount += 1;
									ft_putstr("OR new fact: ");
									ft_putendl(all->facts);
								}
							}

						}
					}
				}
				all->stmts = all->stmts->next;
			}
			all->stmts = head;
			i++;
		}
		i = 0;
		cnt++;
	}
}

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

char	ft_symbol(char *str)
{
	char *sym;
	int i;
	char *symfound;

	i = 0;
	sym = "+|";

	while (sym[i])
	{
		symfound = ft_strchr(str, sym[i]);
		if (symfound != NULL)
		{
			return (symfound[0]);
		}
		i++;
	}
	return ('z');
}

