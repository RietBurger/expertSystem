#include "expert.h"

int	ft_issym(char c)
{
	if (c == '+' || c == '|')
		return (1);
	return (0);
}


char	*create_stmt(t_stmts *stmts)
{
	char *var;
	char *syms;
	char *eq;
	char *newstmt;
	
	int maxlen;
	int varc;
	int symsc;
	int stmtc;
	int i;

	varc = symsc = stmtc = i = 0;
	maxlen = ft_strlen(stmts->stmt);
	var = ft_strnew(maxlen);
	syms = ft_strnew(maxlen);
	eq = " == 't' ";
	while (stmts->stmt[i])
	{
		if (ft_issym(stmts->stmt[i]) == 1)
		{
			

		}
		else if(ft_isvar(stmts->stmt[i]) == 1)
		{

		}
		else
			i++;
		i++;
	}

	return (newstmt);
}
