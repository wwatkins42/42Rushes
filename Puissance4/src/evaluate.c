/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:19:33 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/28 19:47:18 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		evaluate(t_env *e)
{
	int		i;
	int		j;
	int     weight;

	weight = 0;
	i = -1;
	while (++i < e->width)
	{
		j = 0;
		while (j < e->height && e->board[j][i] == '.')
		{
			j++;
			if (j < e->height && e->board[j][i] != '.' && j - 1 >= 0)
			{
				weight += count_horizontal(e, i, j - 1);
				weight += count_vertical(e, i, j - 1);
				weight += count_diagonal_left(e, i, j - 1);
				weight += count_diagonal_right(e, i, j - 1);
			}
		}
	}
	return (weight);
}

int     count_horizontal(t_env *e, int i, int j)
{
	int		sum;

	sum = 0;
	if (i + 1 < e->width && e->board[j][i + 1] == 'X')
	{
		if (i + 2 < e->width && e->board[j][i + 2] == 'X')
			sum += 100;
		sum += 10;
	}
	else if (i + 1 < e->width && e->board[j][i + 1] == 'O')
	{
		if (i + 2 < e->width && e->board[j][i + 2] == 'O')
			sum -= 100;
		sum -= 10;
	}
	return (sum);
}

int     count_vertical(t_env *e, int i, int j)
{
	int		sum;

	sum = 0;
	if (j + 1 < e->height && e->board[j + 1][i] == 'X')
	{
		if (j + 2 < e->height && e->board[j + 2][i] == 'X')
			sum += 100;
		sum += 10;
	}
	else if (j + 1 < e->height && e->board[j + 1][i] == 'O')
	{
		if (j + 2 < e->height && e->board[j + 2][i] == 'O')
			sum -= 100;
		sum -= 10;
	}
	return (sum);
}

int     count_diagonal_left(t_env *e, int i, int j)
{
	int	sum;

	sum = 0;
	if (i - 1 >= 0 && j + 1 < e->height && e->board[j + 1][i - 1] == 'X')
	{
		if (i - 2 >= 0 && j + 2 < e->height && e->board[j + 2][i - 2] == 'X')
			sum += 100;
		sum += 10;
	}
	if (i - 1 >= 0 && j - 1 >= 0 && e->board[j - 1][i - 1] == 'X')
	{
		if (i - 2 >= 0 && j - 2 >= 0 && e->board[j - 2][i - 2] == 'X')
			sum += 100;
		sum += 10;
	}
	if (i - 1 >= 0 && j + 1 < e->height && e->board[j + 1][i - 1] == 'O')
	{
		if (i - 2 >= 0 && j + 2 < e->height && e->board[j + 2][i - 2] == 'O')
			sum -= 100;
		sum -= 10;
	}
	if (i - 1 >= 0 && j - 1 >= 0 && e->board[j - 1][i - 1] == 'O')
	{
		if (i - 2 >= 0 && j - 2 >= 0 && e->board[j - 2][i - 2] == 'O')
			sum -= 100;
		sum -= 10;
	}
	return (sum);
}

int     count_diagonal_right(t_env *e, int i, int j)
{
	int	sum;

	sum = 0;
	if (i + 1 < e->width && j + 1 < e->height && e->board[j + 1][i + 1] == 'X')
	{
		if (i + 2 < e->width && j + 2 < e->height && e->board[j + 2][i + 2] == 'X')
			sum += 100;
		sum += 10;
	}
	if (i + 1 < e->width && j - 1 >= 0 && e->board[j - 1][i + 1] == 'X')
	{
		if (i + 2 < e->width && j - 2 >= 0 && e->board[j - 2][i + 2] == 'X')
			sum += 100;
		sum += 10;
	}
	if (i + 1 < e->width && j + 1 < e->height && e->board[j + 1][i + 1] == 'O')
	{
		if (i + 2 < e->width && j + 2 < e->height && e->board[j + 2][i + 2] == 'O')
			sum -= 100;
		sum -= 10;
	}
	if (i + 1 < e->width && j - 1 >= 0 && e->board[j - 1][i + 1] == 'O')
	{
		if (i + 2 < e->width && j - 2 >= 0 && e->board[j - 2][i + 2] == 'O')
			sum -= 100;
		sum -= 10;
	}
	return (sum);
}
