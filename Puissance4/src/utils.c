/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:34:27 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/28 22:05:13 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		board_create(t_env *e)
{
	int	i;
	int	j;

	i = -1;
	if ((e->board = (char**)malloc(sizeof(char*) * e->h)) == NULL)
		return (-1);
	while (++i < e->h)
	{
		if ((e->board[i] = (char*)malloc(sizeof(char) * e->w)) == NULL)
			return (-1);
		j = -1;
		while (++j < e->w)
			e->board[i][j] = '.';
	}
	return (0);
}

void	board_insert(t_env *e, int input, int p)
{
	int j;

	j = 0;
	while (j < e->h && e->board[j][input] == '.')
		j++;
	if (j - 1 >= 0)
	{
		p == 2 ? e->board[j - 1][input] = 'X' : 0;
		p == 1 ? e->board[j - 1][input] = 'O' : 0;
	}
}

void	board_delete(t_env *e, int input)
{
	int j;

	j = 0;
	while (j < e->h && e->board[j][input] == '.')
		j++;
	e->board[j][input] = '.';
}

void	board_disp(t_env *e)
{
	int	i;
	int	j;

	j = -1;
	while (++j < e->h + 1)
	{
		i = -1;
		while (++i < e->w)
		{
			if (j == 0)
			{
				set_color(i);
				ft_putnbr(i % 10);
			}
			else
			{
				e->board[j - 1][i] == 'X' ? ft_putstr(COLR_RED) : 0;
				e->board[j - 1][i] == 'O' ? ft_putstr(COLR_YELLOW) : 0;
				ft_putchar(e->board[j - 1][i]);
			}
			ft_putstr(COLR_END);
			i < e->w - 1 ? ft_putstr("  ") : 0;
		}
		ft_putchar('\n');
	}
}

int		board_complete(t_env *e)
{
	int	i;
	int	j;

	j = -1;
	while (++j < e->h)
	{
		i = -1;
		while (++i < e->w)
		{
			if (e->board[j][i] == '.')
				return (0);
		}
	}
	return (1);
}
