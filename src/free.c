#include "expert.h"

void	free_stmts(t_stmts *b)
{
	t_stmts *tmp_l;

	while (b != NULL)
	{
		tmp_l = b;
		b = b->next;
		free(tmp_l->stmt);
		free(tmp_l->valImp);
		free(tmp_l);
	}
	free(b);
}

/*
void	free_find(t_find *i)
{
	t_find	*tmp_i;

	while (i != NULL)
	{
		tmp_i = i;
		i = i->next;
		free(tmp_i->str);
		free(tmp_i);
	}
	free(i);
}

void	free_all(t_board *b, t_input *i)
{
	free_board(b);
	free_input(i);
}
*/
