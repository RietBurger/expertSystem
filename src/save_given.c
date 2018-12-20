#include "expert.h"

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
								ft_new_fact(all, all->stmts->decision[1]);

								/*
								if (ft_strchr(all->facts, all->stmts->decision[1]) == NULL)
								{
									all->facts[all->fcount] = all->stmts->decision[1];
									all->fcount += 1;
									ft_putstr("AND new fact: ");
									ft_putendl(all->facts);
								}
								*/
							}
						}
						if (all->stmts->operatorSym == '|')
						{
							if (split1 == 't' || split2 == 't')
							{
								ft_new_fact(all, all->stmts->decision[1]);
								/*
								if (ft_strchr(all->facts, all->stmts->decision[1]) == NULL)
								{
									all->facts[all->fcount] = all->stmts->decision[1];
									all->fcount += 1;
									ft_putstr("OR new fact: ");
									ft_putendl(all->facts);
								}
								*/
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

void	ft_new_fact(t_g *all, char newf)
{
	if (ft_strchr(all->facts, newf) == NULL)
	{
		all->facts[all->fcount] = newf;
		all->fcount += 1;
		ft_putstr("NEW facts: ");
		ft_putendl(all->facts);
	}
}
