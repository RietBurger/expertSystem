#include "expert.h"

char	*trimstr(char *str)
{
	int i, j;
	char *retstr;

	i = j = 0;

	retstr = ft_strnew(ft_strlen(str));

	while (str[i])
	{
		if (ft_iswhtspc(str[i]) == 1)
			i++;
		else
		{
			retstr[j] = str[i];
			i++;
			j++;
		}
	}
	retstr[j] = '\0';
	return (retstr);
}

t_stmts			*read_file(t_g *all)
{
	t_stmts		*head; // head is to be kept and returned to struct t_g all so that we can access the list at all times
	t_stmts		*node; // this will be the actual nodes 
	char		*temp;
	char		*temp1;
	head = NULL;
	int i;

	i = 0;
	while (get_next_line(0, &all->gnl))
	{
		//ft_putstr("all->gnl: ");
		//ft_putendl(all->gnl);

		if (all->gnl[0] != '#')
		{
			if (head == NULL)
			{
				head = (t_stmts *)ft_memalloc(sizeof(t_stmts));
				node = head;
			}
			//to trim str... or not..? ONLY ONCE NO ABSOLUTE POSITIONS ARE BEING USED!
			//node->stmt = trimstr(all->gnl);
			node->stmt = all->gnl;
			//temp1 = trimstr(all->gnl);
			temp = ft_strchr(node->stmt, '#');
		//	if (temp == NULL)
		//		node->stmt = all->gnl;
			if (temp)
			{
				node->stmt = ft_strsplit(node->stmt, '#')[0];
			}
			node->nodenr = i; // number the node (for future use)

			// to test
			ft_putstr("node->stmt: ");
			ft_putendl(node->stmt);
			i++;

			node->next = (t_stmts *)ft_memalloc(sizeof(t_stmts));
			node = node->next;
		}
	}
	node->next = NULL; //end list
	//	ft_putendl("file read completed successfully");
	return (head); //return the head
}

