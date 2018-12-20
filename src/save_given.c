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
			while (all->stmts->next && all->stmts->decision)
			{
				if (all->find[i] == all->stmts->decision[1])
				{
					all->stmts->operatorSym = ft_symbol(all->stmts->data);
					splits = ft_strsplit(all->stmts->data, all->stmts->operatorSym);
					if (splits != NULL)
					{

						split1 = ft_match(splits[0], all);
						if (splits[1] != NULL)
							split2 = ft_match(splits[1], all);
						if (all->stmts->operatorSym == '+')
						{
							if (split1 == 't' && split2 == 't') {
								ft_new_fact(all, all->stmts->decision[1]);
							} else {
								ft_new_find(all, splits[0]);
								ft_new_find(all, splits[1]);
							}
						}
						if (all->stmts->operatorSym == '|')
						{
							if (split1 == 't' || split2 == 't')
							{
								ft_new_fact(all, all->stmts->decision[1]);
							}
						}
						if (all->stmts->operatorSym == 'z')
						{
							if (split1 == 't')
							{
								ft_new_fact(all, all->stmts->decision[1]);
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
	}
}

void	ft_new_find(t_g *all, char *splits)
{
	int i;

	i = 0;

	while (splits[i] == ' ')
		i++;
	if (ft_strchr(all->find, splits[i]) == NULL)
	{
		all->find[all->findc] = splits[i];
		all->findc += 1;
	}
}
