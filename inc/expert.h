#ifndef EXPERT_H
# define EXPERT_H

# include <stdio.h>
# include "../libft/libft.h"

typedef struct			s_stmts
{
	char				*stmt; //full statement
	int					nodenr;
	char				*valImp; //value after =>
	struct s_stmts		*next;
}						t_stmts;

typedef struct			s_find
{
	char				valF;
	int					stateBool;
	struct s_find		*next;
}						t_find;

typedef struct			s_given
{
	char				valG;
	int					stateBool;
	struct s_given		*next;
}						t_given;

typedef struct			s_values
{
	char				*val;
	int					found;
	int					stateBool;
	int					parentNodenr;
	int					implied;
	struct s_values		*next;
}						t_values;

typedef struct			s_g
{
	t_stmts				*stmts;
	t_find				*find;
	t_given				*given;
	t_values			*values;
	char				*gnl;
}						t_g;

t_stmts					*read_file(t_g *all);
t_find					*save_find(t_g *all);
t_given					*save_given(t_g *all);
t_values				*save_values(t_g *all);

//void					save_piece(t_input *node, t_g *all);
//t_board					*save_board(t_input *node, t_g *all);

//void	free_all(t_board *b, t_input *i); 
void	free_stmts(t_stmts *b); //to be called by free_all()
//void	free_input(t_input *i); //to be called by free_all()

#endif
