#include "expert.h"

t_stmts			*read_file(t_g *all)
{
	t_stmts		*head; // head is to be kept and returned to struct t_g all so that we can access the list at all times
	t_stmts		*node; // this will be the actual nodes 

	head = NULL;
	int i;

	i = 0;
	while (get_next_line(0, &all->gnl))
	{
		if (head == NULL)
		{
			head = (t_stmts *)ft_memalloc(sizeof(t_stmts));
			node = head;
		}
		node->stmt = all->gnl;
		node->nodenr = i; // number the node (for future use)
		node->next = (t_stmts *)ft_memalloc(sizeof(t_stmts));
//		if (node->stmt == NULL || (ft_strcmp(node->stmt, "\0") == 0))
//			error();
		node = node->next;
		i++;
	}
	node->next = NULL; //end list
	return (head); //return the head
}
