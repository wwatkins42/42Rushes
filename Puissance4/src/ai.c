/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:12:54 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/28 11:29:30 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ai_algorithm(t_env *e)
{
	int	input;

	input = minimax(e, MAX_DEPTH);
	//board_insert(e, input, AI);
	return (0);
}

int		minimax(t_env *e, int depth)
{
	int i;
	int	v;
	int	bestvalue;
	int	move;

	i = -1;
	bestvalue = -MAX_VALUE;
	while (++i < e->width)
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
	return (move);
}

int		min(t_env *e, int p, int depth)
{
	int	i;
	int	v;
	int vmin;

	i = 0;
	if (depth == 0 || check_win(e, p) == p)
		return (-MAX_VALUE);
	//	return (evaluate(e, move));
	else
	{
		vmin = MAX_VALUE;
		while (i < e->width)
		{
			if (e->board[0][i] == '.')
			{
				board_insert(e, i, p);
				v = max(e, p % 2 + 1, depth - 1);
				vmin = (vmin < v ? vmin : v);
				board_delete(e, i);
			}
			i++;
		}
	}
	return (vmin);
}

int		max(t_env *e, int p, int depth)
{
	int	i;
	int	v;
	int	vmax;

	i = 0;
	if (depth == 0 || check_win(e, p) == p)
		return (MAX_VALUE);
	//	return (evaluate(e, move));
	else
	{
		v = -MAX_VALUE;
		while (i < e->width)
		{
			if (e->board[0][i] == '.')
			{
				board_insert(e, i, p);
				v = min(e, p % 2 + 1, depth - 1);
				vmax = (vmax > v ? vmax : v);
				board_delete(e, i);
			}
			i++;
		}
	}
	return (vmax);
}
