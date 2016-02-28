/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:12:54 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/28 20:51:47 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		minimax(t_env *e, int depth)
{
	int i;
	int	v;
	int	bestvalue;
	int	move;

	i = -1;
	bestvalue = -MAX_VALUE;
	while (++i < e->w)
	{
		if (e->board[0][i] == '.')
		{
			board_insert(e, i, 2);
			v = min(e, 1, depth);
			if (v > bestvalue)
			{
				bestvalue = v;
				move = i;
			}
			board_delete(e, i);
		}
	}
	move = displace(e, bestvalue, move);
	return (move);
}

int		min(t_env *e, int p, int depth)
{
	int	i;
	int	v;
	int vmin;

	i = -1;
	if (depth == 0 && check_win(e, p) == 0)
		return (evaluate(e));
	else if (check_win(e, p) == 1)
		return (-MAX_VALUE + (MAX_DEPTH - depth) * 10);
	else
	{
		vmin = MAX_VALUE;
		while (++i < e->w)
		{
			if (e->board[0][i] == '.')
			{
				board_insert(e, i, p);
				v = max(e, p % 2 + 1, depth - 1);
				vmin = (v < vmin ? v : vmin);
				board_delete(e, i);
			}
		}
	}
	return (vmin);
}

int		max(t_env *e, int p, int depth)
{
	int	i;
	int	v;
	int	vmax;

	i = -1;
	if (depth == 0 && check_win(e, p) == 0)
		return (evaluate(e));
	else if (check_win(e, p) == 1)
		return (MAX_VALUE - (MAX_DEPTH - depth) * 10);
	else
	{
		vmax = -MAX_VALUE;
		while (++i < e->w)
		{
			if (e->board[0][i] == '.')
			{
				board_insert(e, i, p);
				v = min(e, p % 2 + 1, depth - 1);
				vmax = (v > vmax ? v : vmax);
				board_delete(e, i);
			}
		}
	}
	return (vmax);
}

int		displace(t_env *e, int bestvalue, int move)
{
	int i;

	if (bestvalue == -MAX_VALUE)
	{
		i = 0;
		while (e->board[0][i] != '.')
			i++;
		move = i;
	}
	return (move);
}
