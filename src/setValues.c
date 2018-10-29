#include "expert.h"

void	setValues(t_g *all)
{
	t_find	*fnode;
	t_given *gnode;

	fnode = all->find;
	gnode = all->given;

	while (fnode->next)
	{
		ft_putstr("this is fnode->valF ");
		ft_putendl(&fnode->valF);
		while (gnode->next)
		{
			ft_putstr("this is gnode->valG ");
			ft_putendl(&gnode->valG);
			if (gnode->valG == fnode->valF && fnode->stateBool == 0)
			{
				fnode->stateBool = 1;
				ft_putstr("this is fnode->valF and gnode->valG: ");
				ft_putendl(&fnode->valF);
				ft_putendl(&gnode->valG);
			}
			gnode = gnode->next;
		}
		gnode = all->given;
		fnode = fnode->next;
	}
}

void	matchValues(t_g *all)
{
	t_values	*tnode;
	t_given		*gnode;

	gnode = all->given;
	tnode = all->values;

	while (tnode->next)
	{
		ft_putstr("tnode->val at top: ");
		ft_putendl(tnode->val);
		while (gnode->next)
		{
			ft_putstr("gnode->valG at top: ");
			ft_putendl(&gnode->valG);
			if (gnode->valG == tnode->val[0]) 
			{
				ft_putstr("this is tnode->val matching gnode->valG: ");
				ft_putendl(tnode->val);
				tnode->stateBool = 1;
			}
			gnode = gnode->next;
		}
		gnode = all->given;
		tnode = tnode->next;
	}
}

/*
void		impValues(t_g *all)
{
	t_given		*gnode;
	t_stmts		*stnode;

	tnode = all->given;
	stnode = all->stmts;

	while (t_given->next)
	{
		
	}
}
*/
