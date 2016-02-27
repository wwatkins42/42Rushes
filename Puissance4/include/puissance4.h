/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:06:49 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/27 19:01:14 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <time.h>
# include <stdio.h> // TEMP

enum { HUMAN, AI };

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX_DEPTH 2

# define COLR_BLUE "\e[34m"
# define COLR_END "\e[0m"

typedef struct	s_tree
{
	int				type;
	int				weight;
	struct s_tree	**node;
}				t_tree;

typedef struct	s_env
{
	t_tree	*tree;
	char	**board;
	char	**constant;
	char	**copy;
	int		*moves;
	int		width;
	int		height;
	int		input;
	short	game;
	int		j;
}				t_env;

/*
**	main.c
*/

int				args_get(t_env *e, int argc, char **argv);
int				str_isdigit(char *str);

/*
**	utils.c
*/

int				board_create(t_env *e);
int				board_insert(t_env *e, int input, char **board, short player);
int				board_delete(t_env *e, int j, int input, char **board);
char			**board_copy(t_env *e, char **board);
int				board_disp(t_env *e, char **board);
void			set_color(int i);

/*
**	core.c
*/

int				game_loop(t_env *e);
int				turn_player(t_env *e);
int				turn_ia(t_env *e);
int				get_input(t_env *e);

/*
**	check_win.c
*/

int				check_win(t_env *e, short player);
int				check_horizontal(t_env *e, int i, int j, char c);
int				check_vertical(t_env *e, int i, int j, char c);
int				check_diagonal_left(t_env *e, int i, int j, char c);
int				check_diagonal_right(t_env *e, int i, int j, char c);

/*
**	ai.c
*/

int				ai_algorithm(t_env *e);
int				minimax(t_env *e, int move, int j, int depth, int maximizing);
int				min(t_env *e, int move, int depth);
int				max(t_env *e, int move, int depth);

/*
**	evaluate.c
*/

int				evaluate(t_env *e, int j, int move);
int				weight_horizontal(t_env *e, int j, int move);
int				weight_vertical(t_env *e, int j, int move);
int				weight_diagonal_left(t_env *e, int j, int move);
int				weight_diagonal_right(t_env *e, int j, int move);

#endif
