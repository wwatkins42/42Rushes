/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:12:54 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/28 13:18:43 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ai_algorithm(t_env *e)
{
	int	input;

	input = minimax(e, MAX_DEPTH);
	board_insert(e, input, 2);
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
			board_insert(e, i, 1);
			v = min(e, 2, depth);
			if (v > bestvalue)
			{
				bestvalue = v;
				move = i;
			}
			board_delete(e, i);
		}
	}
/*	if (bestvalue == -MAX_VALUE)
		minimax(e, depth - 1);
	else
		board_insert(e, move, 2);*/
	return (move);
}

int		min(t_env *e, int p, int depth)
{
	int	i;
	int	v;
	int vmin;

	i = 0;
	if (depth == 0 || check_win(e, p) == p)
		//return (-MAX_VALUE);
		return(-evaluate(e, e->prev));
	else
	{
		vmin = MAX_VALUE;
		while (i < e->width)
		{
			if (e->board[0][i] == '.')
			{
				board_insert(e, i, p);
				e->prev = i;
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
		//return (MAX_VALUE);
		return(evaluate(e, e->prev));
	else
	{
		v = -MAX_VALUE;
		while (i < e->width)
		{
			if (e->board[0][i] == '.')
			{
				board_insert(e, i, p);
				e->prev = i;
				v = min(e, p % 2 + 1, depth - 1);
				vmax = (vmax > v ? vmax : v);
				board_delete(e, i);
			}
			i++;
		}
	}
	return (vmax);
}
