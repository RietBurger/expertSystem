#include "expert.h"

void	ft_find(t_g *all)
{
	t_stmts *head;
	int i, j, spcount, cnt, stcount, loops, decisionc, fcount;
	
	i = 0;
	cnt = 0;
	stcount = 0;
	spcount = 0;
	fcount = 0;
	loops = 0;
	decisionc = 0;
	head = all->stmts;

	while (cnt < all->fcount)
	{
		while (all->find[i])
		{
			fcount++;
			while (all->stmts->next && all->stmts->decision && all->stmts->data)
			{
				decisionc = ft_strlen(all->stmts->decision);
				if (all->find[i] == all->stmts->decision[1])
				{
					ft_decision_found(all, all->stmts);
				}
				if (decisionc > 2)
				{
					stcount = ft_match_chr(all->stmts->decision[1], all);
					if (stcount == 't')
					{
						ft_new_fact(all, all->stmts->decision[5]);
						//ft_remove_decision(all, all->stmts->decision[1]); // this is character sent in last
					}


				}
				all->stmts = all->stmts->next;
				loops++;
				decisionc = 0;
			}
			all->stmts = head;
			i++;
		}
		i = 0;
		cnt++;
		all->stmts = head;
	}
	ft_putstr("Loops: ");
	ft_putnbr(loops);
	ft_putchar('\n');
}

void	ft_decision_found(t_g *all, t_stmts *curr_stmt)
{
	char **splits;
	char split1, split2;

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
				ft_remove_find(all, splits[0]);
				ft_remove_find(all, splits[1]);
				//ft_remove_decision(all, all->stmts->decision[1]); // this is character sent in last
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
				if (split1 == 't')
					ft_remove_find(all, splits[0]);
				if (split2 == 't')
					ft_remove_find(all, splits[1]);

				//ft_remove_decision(all, all->stmts->decision[1]); // this is character sent in last
			} else {
				
				ft_new_find(all, splits[0]);
				ft_new_find(all, splits[0]);
			}
		}
		if (all->stmts->operatorSym == 'z')
		{
			if (split1 == 't')
			{
				ft_new_fact(all, all->stmts->decision[1]);
				ft_remove_find(all, splits[0]);
				//ft_remove_decision(all, all->stmts->decision[1]); // this is character sent in last

			} else {
				ft_new_find(all, splits[0]);
			}
		}
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

void	ft_remove_find(t_g *all, char *splits)
{
	int	c;
	int	i;

	c = i = 0;

	while (splits[i] == ' ')
		i++;
	while (all->find[c] != splits[i])
		c++;

	ft_memmove(&all->find[c], &all->find[c + 1], ft_strlen(all->find) - 1);
}

void	ft_remove_decision(t_g *all, char split)
{
	int c;

	c = 0;

	while (all->find[c] != split)
		c++;

	ft_memmove(&all->find[c], &all->find[c + 1], ft_strlen(all->find) - 1);
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

void	ft_new_find_chr(t_g *all, char splits)
{
	if (ft_strchr(all->find, splits) == NULL)
	{
		all->find[all->findc] = splits;
		all->findc += 1;
	}
}
