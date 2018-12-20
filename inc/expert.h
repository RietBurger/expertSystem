#ifndef EXPERT_H
# define EXPERT_H

# include <stdio.h>
# include "../libft/libft.h"

typedef struct			s_stmts
{
	char				*stmt; //full statement
	int				nodenr;
	char				*decision; //value after =>
	char				*data;
	char				operatorSym;
	struct s_stmts		*next;
}						t_stmts;

typedef struct			s_result
{
	char			valR;
	int			stateBool;
	struct s_result		*next;
}				t_result;

typedef struct			s_g
{
	t_stmts				*stmts;
	t_result			*result;
	int				possible_vars;
	char				*gnl;
	char				*find;
	char				*facts;
	int				fcount;
}						t_g;

t_stmts			*read_file(t_g *all);
t_result		*save_results(t_g *all);
void			sort_info(t_g *all);
void			ft_find(t_g *all);
char			ft_symbol(char *str);
char			ft_match(char *temp, t_g *all);
void			ft_new_fact(t_g *all, char newf);
void	free_stmts(t_stmts *b); //to be called by free_all()
#endif
