/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:12:54 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/27 19:01:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ai_algorithm(t_env *e)
{
	int	input;

	input = minimax(e, 0, 0, MAX_DEPTH, 1);
	return (input);
}
/*
int		minimax(t_env *e, int depth)
{
	int i;
	int	maxime;
	int	val_fils;
	int	coup;

	i = -1;
	maxime = -2000;
	while (++i < e->width)
	{
		val_fils = min(e, i, depth);
		if (val_fils > maxime)
		{
			maxime = val_fils;
			coup = i;
		}
	}
	return (coup);
}

int		min(t_env *e, int move, int depth)
{
	int	i;
	int	j;
	int	v_fils;
	int v_min;

	i = 0;
	e->moves[MAX_DEPTH - depth - 1] = move;
	if (depth == 0)
		return (evaluate(e, move));
	else
	{
		v_min = 2000;
		j = board_insert(e, move, e->board, AI);
		while (i < e->width)
		{
			v_fils = max(e, i, depth - 1);
			v_min = (v_min < v_fils ? v_min : v_fils);
			i++;
		}
		board_delete(e, j, move, e->board);
	}
	return (v_min);
}

int		max(t_env *e, int move, int depth)
{
	int	i;
	int	j;
	int	v_fils;
	int	v_max;

	i = 0;
	e->moves[MAX_DEPTH - depth - 1] = move;
	if (depth == 0)
		return (evaluate(e, move));
	else
	{
		v_max = -2000;
		j = board_insert(e, move, e->board, AI);
		while (i < e->width)
		{
			v_fils = min(e, i, depth - 1);
			v_max = (v_max > v_fils ? v_max : v_fils);
			i++;
		}
		board_delete(e, j, move, e->board);
	}
	return (v_max);
}*/

int		minimax(t_env *e, int move, int j, int depth, int maximizing)
{
	int	i;
	int	v;
	int	best_value;

	if (depth == 0 || check_win(e, AI))
		return (evaluate(e, j, move));
	if (maximizing)
	{
		depth != MAX_DEPTH ? j = board_insert(e, move, e->board, HUMAN) : 0;
		i = 0;
		best_value = -1000;
		while (i < e->width)
		{
			v = minimax(e, i, j, depth - 1, 0);
			best_value = (best_value > v ? best_value : v);
			i++;
		}
		board_disp(e, e->board);
		board_delete(e, j, move, e->board);
		return (best_value);
	}
	else
	{
		depth != MAX_DEPTH ? j = board_insert(e, move, e->board, AI) : 0;
		i = 0;
		best_value = 1000;
		while (i < e->width)
		{
			v = minimax(e, i, j, depth - 1, 1);
			best_value = (best_value < v ? best_value : v);
			i++;
		}
		board_disp(e, e->board);
		board_delete(e, j, move, e->board);
		return (best_value);
	}
}
