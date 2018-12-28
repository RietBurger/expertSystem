#include "expert.h"

void	ft_find(t_g *all)
{
	t_stmts *head;
	int i, cnt, stcount, loops, decisionc, fcount;

	i = 0;
	cnt = 0;
	stcount = 0;
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
				//ft_putstr("this it decision[1]: ");
				//ft_putchar(all->stmts->decision[1]);
				//ft_putchar('\n');
				decisionc = ft_strlen(all->stmts->decision);
				if (all->find[i] == all->stmts->decision[1]) //NOT CATERING FOR IF FIND IS NOWHERE IN DECISIONS...
				{
					ft_decision_found(all, all->stmts);
				}
				if (decisionc > 2) // this means 2 decision vars
				{
					stcount = ft_match_chr(all->stmts->decision[1], all);
					//find second symbol... currently based on assumption its a +
					if (stcount == 't') //if decision var 1 is true, then so is 2nd one
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
	char *notOp, *notOpDa, *notOpDe;
	all->stmts->operatorSym = ft_symbol(all->stmts->data);
	splits = ft_strsplit(all->stmts->data, all->stmts->operatorSym);
	if (splits != NULL)
	{
		//ft_putstr("this is splits[0] in decision_found: ");
		//ft_putendl(splits[0]);
		split1 = ft_match(splits[0], all);
		if (splits[1] != NULL)
			split2 = ft_match(splits[1], all);
	/*
		notOp = ft_strchr(all->stmts->stmt, '!');
		if (notOp)
		{
			ft_putendl(notOp);
			notOpDa = ft_strchr(all->stmts->data, '!');
			notOpDe = ft_strchr(all->stmts->decision, '!');
			if (notOpDe)
			{
				ft_putstr("notOpDe: ");
				ft_putendl(notOpDe);
			}
			if (notOpDa)
			{
				ft_putstr("notOpDa: ");
				ft_putendl(notOpDa);
			}
			
		}
	*/	
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
		if (all->stmts->operatorSym == '^')
		{
			if (split1 == 't' && split2 == 'f')
			{
				ft_putendl("1 is T, 2 is F");
				ft_new_fact(all, all->stmts->decision[1]);
			}
			else if (split2 == 't' && split1 == 'f')
			{
				ft_putendl("2 is T, 1 is F");
				ft_new_fact(all, all->stmts->decision[1]);
			}
			else if (split1 == 't' && split2 == 't')
			{
				ft_putendl("both on ^ is true");
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
	/*
	   if (all->facts[0] == 'i')
	   ft_putendl("found 'i' in ft_new_fact");
	   else
	   {
	   ft_putstr("all->facts[0]: ");
	   ft_putchar(all->facts[0]);
	   ft_putchar('\n');
	   }
	   */
	ft_putendl("this is in ft_new_fact");
	//ft_putnbr(all->fcount);
	//ft_putchar('\n');
	if (all->facts && newf)
	{
		if (ft_strchr(all->facts, newf) == NULL)
		{
			all->facts[all->fcount] = newf;
			all->fcount += 1;
		}
	} else {
		ft_putendl("all->facts or newf seems to be null");
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
