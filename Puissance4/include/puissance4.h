/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:06:49 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/27 13:45:03 by wwatkins         ###   ########.fr       */
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
	int		width;
	int		height;
	int		input;
	short	game;
}				t_env;

/*
**	main.c
*/

int				args_get(t_env *e, int argc, char **argv);

/*
**	utils.c
*/

int				board_create(t_env *e);
int				board_insert(t_env *e, short player);
int				board_disp(t_env *e);
void			set_color(int i);
int				str_isdigit(char *str);

/*
**	core.c
*/

int				game_loop(t_env *e);
int				turn_player(t_env *e);
int				turn_ia(t_env *e);
int				get_input(t_env *e);

/*
**	check_victory.c
*/

int				check_win(t_env *e, short player);
int				check_horizontal(t_env *e, int i, int j, char c);
int				check_vertical(t_env *e, int i, int j, char c);
int				check_diagonal_left(t_env *e, int i, int j, char c);
int				check_diagonal_right(t_env *e, int i, int j, char c);

#endif
