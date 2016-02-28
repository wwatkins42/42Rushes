/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:06:49 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/28 20:30:24 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <time.h>
# include <stdio.h> // TEMP

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define COLR_BLUE "\e[34m"
# define COLR_RED "\e[31m"
# define COLR_YELLOW "\e[33m"
# define COLR_END "\e[0m"
# define MAX_DEPTH 5
# define MAX_VALUE 1000

enum { HUMAN, AI };

typedef struct	s_env
{
	char	**board;
	int		*moves;
	int		width;
	int		height;
	int		input;
	int		j;
	int		prev;
	short	game;
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
int				board_insert(t_env *e, int input, int p);
int				board_delete(t_env *e, int input);
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

int				check_win(t_env *e, int p);
int				check_horizontal(t_env *e, int i, int j, char c);
int				check_vertical(t_env *e, int i, int j, char c);
int				check_diagonal_left(t_env *e, int i, int j, char c);
int				check_diagonal_right(t_env *e, int i, int j, char c);

/*
**	ai.c
*/

int				ai_algorithm(t_env *e);
int				minimax(t_env *e, int depth);
int				min(t_env *e, int p, int depth);
int				max(t_env *e, int p, int depth);

/*
**	evaluate.c
*/

int				evaluate(t_env *e);
int				count_horizontal(t_env *e, int i, int j, int weight);
int				count_vertical(t_env *e, int i, int j, int weight);
int				count_diagonal_left(t_env *e, int i, int j, int weight);
int				count_diagonal_right(t_env *e, int i, int j, int weight);

#endif
