/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:19:33 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/27 19:01:57 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		evaluate(t_env *e, int j, int move)
{
	int     weight;

	weight = 0;
	board_disp(e, e->board);
	printf("(%d, %d)\n", j, move);
	weight = weight_horizontal(e, j, move);
	return (weight);
}

int		weight_horizontal(t_env *e, int j, int move)
{
	int		i;
	int		weight;
	char	c;

	c = e->board[j][move];
	weight = 1;
	i = move;
	while (++i < e->width)
	{
		if (e->board[j][i] == c)
			weight *= 10;
	}
	i = move;
	while (--i > 0)
	{
		if (e->board[j][i] == c)
			weight *= 10;
		if (e->board[j][i] != c)
			break ;
	}
	printf("%d\n", weight);
	return (weight);
}
