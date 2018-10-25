#include "expert.h"

t_given		*save_given(t_g *all)
{
	t_given		*head;
	t_given		*node;
	t_stmts		*stmt_head;
	char		*str;
	int			i;

	i = 1;
	head = NULL;
	stmt_head = all->stmts;
	while (all->stmts->next)
	{
		if (all->stmts->stmt[0] == '=')
		{
			str = ft_strdup(all->stmts->stmt);
			while (str[i])
			{
				//ft_putchar(str[i]);
				if (head == NULL)
				{
					head = (t_given *)ft_memalloc(sizeof(t_given));
					node = head;
				}
				node->valG = str[i];
				node->stateBool = 1;
				//testing
				ft_putendl("node->valG and node->stateBool to follow:");
				ft_putchar(node->valG);
				ft_putchar('\n');
				ft_putnbr(node->stateBool);
				ft_putchar('\n');
				////
				node->next = (t_given *)ft_memalloc(sizeof(t_given));
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
