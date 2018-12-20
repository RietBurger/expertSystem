#include "expert.h"
/*
void	add_values_to_given(t_g *all)
{
	t_given		*gnode;
	t_values	*vnode;

	gnode = all->given;
	vnode = all->values;

	while (gnode->next)
		gnode = gnode->next;
	ft_putstr("gnode->valG at toooooop: ");
	ft_putendl(&gnode->valG);
	while (vnode->next)
	{
		ft_putstr("checking vnode vals: ");
		ft_putendl(vnode->val);
		if (vnode->stateBool == 1 && vnode->found == 0)
		{
			gnode->valG = vnode->val[0];
			gnode->stateBool = 1;
			vnode->found = 1;
			ft_putstr("stateBool == 1 && found == 0: ");
			ft_putendl(&gnode->valG);
			gnode->next = (t_given *)ft_memalloc(sizeof(t_given));
			gnode = gnode->next;

		}
		vnode = vnode->next;
	}
	gnode->next = NULL;
}
*/
int		main(void)
{
	t_g all;

	all.stmts = NULL; 
	ft_putendl("starting main");
	all.stmts = read_file(&all);
	sort_info(&all);
	ft_find(&all);

	free_stmts(all.stmts);
	return (0);
}
