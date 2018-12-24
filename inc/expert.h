#ifndef EXPERT_H
# define EXPERT_H

# include <stdio.h>
# include "../libft/libft.h"

#define orsym ||
#define andsym &&
#define eqt  == 't'

typedef struct			s_stmts
{
	char				*stmt; //full statement
	int				nodenr;
	char				*decision; //value after =>
	char				*data;
	char				operatorSym;
	struct s_stmts		*next;
}						t_stmts;

typedef struct			s_g
{
	t_stmts				*stmts;
	int				possible_vars;
	char				*gnl;
	char				*results;
	int				resultsc;
	char				*find;
	int				findc;
	char				*facts;
	int				fcount;
	char				*undefined;
	int				undefc;
	char				*tester;
}						t_g;

t_stmts			*read_file(t_g *all);
void			sort_info(t_g *all);
void			ft_find(t_g *all);
void			ft_decision_found(t_g *all, t_stmts *curr_stmt);
void			ft_second_decision(t_g *all);
char			ft_symbol(char *str);
char			ft_match(char *temp, t_g *all);
char			ft_match_chr(char temp, t_g *all);
void			ft_new_fact(t_g *all, char newf);
void			ft_new_find(t_g *all, char *splits);
void			ft_new_find_chr(t_g *all, char splits);
void			ft_remove_find(t_g *all, char *splits);
void			ft_remove_decision(t_g *all, char split);
void			ft_undefined(t_g *all);
void			ft_main_output(t_g * all);
void	free_stmts(t_stmts *b); //to be called by free_all()
#endif
