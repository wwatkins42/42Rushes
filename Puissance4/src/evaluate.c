/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:19:33 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/28 17:14:46 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		evaluate(t_env *e, int move)
{
	int		j;
	int     weight;

	weight = 0;
	j = get_height(e, move);
	weight = weight_horizontal(e, j, move);
	return (weight);
}

int		get_height(t_env *e, int move)
{
	int	j;

	j = 0;
	while (j < e->height - 1)
	{
		if (e->board[j][move] != '.')
			break ;
		j++;
	}
	return (j);
}

int		weight_horizontal(t_env *e, int j, int move)
{
	int		weight;
	char	c;

	c = e->board[j][move];
	weight = 1;
	if (move > 1 && e->board[j][move - 1] == c)
		weight *= 10;
	if (move > 2 && e->board[j][move - 1] == c &&
		e->board[j][move - 2] == c)
		weight *= 10;
	if (move < e->width - 1 && e->board[j][move + 1] == c)
		weight *= 10;
	if (move < e->width - 2 && e->board[j][move + 1] == c &&
		e->board[j][move + 2] == c)
		weight *= 10;
	return (weight);
}
