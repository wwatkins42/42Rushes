/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:12:02 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/27 17:06:28 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		check_win(t_env *e, short player)
{
	int	i;
	int	j;

	(void)player;
	j = -1;
	while (++j < e->height)
	{
		i = -1;
		while (++i < e->width)
		{
			if (i < e->width - 3 && e->board[j][i] != '.')
				if (check_horizontal(e, i, j, e->board[j][i]))
					return (1);
			if (j < e->height - 3 && e->board[j][i] != '.')
				if (check_vertical(e, i, j, e->board[j][i]))
					return (1);
			if (j < e->height - 3 && i > 3 && e->board[j][i] != '.')
				if (check_diagonal_left(e, i, j, e->board[j][i]))
					return (1);
			if (j < e->height - 3 && i < e->width - 3 && e->board[j][i] != '.')
				if (check_diagonal_right(e, i, j, e->board[j][i]))
					return (1);
		}
	}
	return (0);
}

int		check_horizontal(t_env *e, int i, int j, char c)
{
	if (e->board[j][i + 1] == c && e->board[j][i + 2] == c &&
		e->board[j][i + 3] == c)
		return (1);
	return (0);
}

int		check_vertical(t_env *e, int i, int j, char c)
{
	if (e->board[j + 1][i] == c && e->board[j + 2][i] == c &&
		e->board[j + 3][i] == c)
		return (1);
	return (0);
}

int		check_diagonal_left(t_env *e, int i, int j, char c)
{
	if (e->board[j + 1][i - 1] == c && e->board[j + 2][i - 2] == c &&
		e->board[j + 3][i - 3] == c)
		return (1);
	return (0);
}

int		check_diagonal_right(t_env *e, int i, int j, char c)
{
	if (e->board[j + 1][i + 1] == c && e->board[j + 2][i + 2] == c &&
		e->board[j + 3][i + 3] == c)
		return (1);
	return (0);
}
