#include "expert.h"

t_values	*save_values(t_g *all)
{
	t_values	*head;
	t_values	*node;
	t_stmts		*stmt_head;
	char		**arr;
	int			i;

	head = NULL;
	stmt_head = all->stmts;
	while (stmt_head->next)
	{
		arr = ft_strsplit(stmt_head->stmt, ' ');
		i = 0;
		while (arr[i])
		{	
			if ((arr[i][0] == '=' && arr[i][1] != '>') || arr[i][0] == '?')
				break;
			if (head == NULL)
			{
				head = (t_values *)ft_memalloc(sizeof(t_values));
				node = head;
			}
			if (ft_strcmp(arr[i - 1], "=>") == 0)
			{
				stmt_head->valImp = ft_strdup(arr[i]);
				node->implied = 1;
				ft_putnbr(node->implied);
				ft_putstr(" = IMPLIED -> ");
				ft_putendl(stmt_head->valImp);
			}

			node->val = ft_strdup(arr[i]);
			node->stateBool = 0;
			node->parentNodenr = stmt_head->nodenr;
			//test values
			ft_putstr("this is node->val: ");
			ft_putendl(node->val);
			ft_putnbr(node->parentNodenr);
			ft_putendl(" = parentNodenr");
			///////////
			node->next = (t_values *)ft_memalloc(sizeof(t_values));
			node = node->next;

			i++;
		}
		node->next = NULL;
		free_args(arr);
		stmt_head = stmt_head->next;
	}
	return (head);
}
