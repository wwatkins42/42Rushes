/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:19:33 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/28 18:17:18 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		evaluate(t_env *e, int p)
{
	int		i;
	int		j;
	int     weight;
	char	c;

	c = (p == 1 ? 'O' : 'X');
	weight = 0;
	i = 0;
	while (i < e->width)
	{
		j = 0;
		while (j < e->height - 1 && e->board[j][i] == '.')
		{
			j++;
			if (j - 1 >= 0 && e->board[j][i] != '.')
			{
				weight += count_horizontal(e, i, j, c);
				weight += count_vertical(e, i, j, c);
				weight += count_diagonal_left(e, i, j, c);
				weight += count_diagonal_right(e, i, j, c);
			}
		}
		i++;
	}
	return (weight);
}

int     count_horizontal(t_env *e, int i, int j, char c)
{
	int		k;
	int		sum;
	char	cn;

	k = 1;
	sum = 0;
	cn = (c == 'X' ? 'O' : 'X');
	while (i + k < e->width && e->board[j][i + k] == c)
	{
		sum += 10;
		k++;
	}
	k = 1;
	while (i + k < e->width && e->board[j][i + k] == cn)
	{
		sum -= 10;
		k++;
	}
	return (sum);
}

int     count_vertical(t_env *e, int i, int j, char c)
{
	int		k;
	int		sum;
	char	cn;

	k = 1;
	sum = 0;
	cn = (c == 'X' ? 'O' : 'X');
	while (j + k < e->height && e->board[j + k][i] == c)
	{
		sum += 10;
		k++;
	}
	k = 1;
	while (j + k < e->height && e->board[j + k][i] == cn)
	{
		sum -= 10;
		k++;
	}
	return (sum);
}

int     count_diagonal_left(t_env *e, int i, int j, char c)
{
	int	k;
	int	sum;

	k = 1;
	sum = 0;
	while (j + k < e->height && i - k > 0 && e->board[j + k][i - k] == c)
	{
		sum += 10;
		k++;
	}
	k = 1;
	while (j - k > 0 && i - k > 0 && e->board[j - k][i - k] == c)
	{
		sum += 10;
		k++;
	}
	return (sum);
}

int     count_diagonal_right(t_env *e, int i, int j, char c)
{
	int	k;
	int	sum;

	k = 1;
	sum = 0;
	while (j + k < e->height && i + k < e->width - 1 &&
			e->board[j + k][i + k] == c)
	{
		sum += 10;
		k++;
	}
	k = 1;
	while (j - k > 0 && i + k < e->width - 1 && e->board[j - k][i + k] == c)
	{
		sum += 10;
		k++;
	}
	return (sum);
}
