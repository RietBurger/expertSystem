#include "expert.h"

t_find		*save_find(t_g *all)
{
	t_find	*head;
	t_find	*node;
	t_stmts	*stmt_head;
	char	*str;
	int		i;

	i = 1;
	head = NULL;
	stmt_head = all->stmts;
	while (all->stmts->next)
	{
		if (all->stmts->stmt[0] == '?')
		{
			str = ft_strdup(all->stmts->stmt);

			while (str[i])
			{
				if (head == NULL)
				{
					head = (t_find *)ft_memalloc(sizeof(t_find));
					node = head;
				}
				node->valF = str[i];
				node->stateBool = 0;
				//testing
				ft_putendl("node->valF and node->stateBool to follow:");
				ft_putchar(node->valF);
				ft_putchar('\n');
				ft_putnbr(node->stateBool);
				ft_putchar('\n');
				////
				node->next = (t_find *)ft_memalloc(sizeof(t_find));
				node = node->next;
				i++;
			}
			node->next = NULL;
			free(str);
		}
		all->stmts = all->stmts->next;
	}
	all->stmts = stmt_head;
	return (head);
}
