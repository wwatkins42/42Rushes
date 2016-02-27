/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:34:27 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/27 18:22:02 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		board_create(t_env *e)
{
	int	i;
	int	j;

	i = -1;
	if ((e->board = (char**)malloc(sizeof(char*) * e->height)) == NULL)
		return (-1);
	while (++i < e->height)
	{
		if ((e->board[i] = (char*)malloc(sizeof(char) * e->width)) == NULL)
			return (-1);
		j = -1;
		while (++j < e->width)
			e->board[i][j] = '.';
	}
	if ((e->moves = (int*)malloc(sizeof(int) * MAX_DEPTH)) == NULL)
		return (-1);
	i = -1;
	while (++i < MAX_DEPTH)
		e->moves[i] = -1;
	return (0);
}

int		board_insert(t_env *e, int input, char **board, short player)
{
	int	j;

	j = 0;
	if (board[0][input] != '.')
		return (-1);
	while (j < e->height - 1)
	{
		if (board[j][input] != '.')
			break ;
		j++;
	}
	board[j][input] != '.' ? j-- : 0;
	board[j][input] = (player == HUMAN ? 'O' : 'X');
	return (j);
}

int		board_delete(t_env *e, int j, int input, char **board)
{
	(void)e;
	j < 0 ? j = 0 : 0;
	input < 0 ? input = 0 : 0;
	board[j][input] = '.';
	return (0);
}

char	**board_copy(t_env *e, char **board)
{
	int     i;
	int     j;
	char	**copy;

	i = -1;
	copy = (char**)malloc(sizeof(char*) * e->height);
	while (++i < e->height)
	{
		copy[i] = (char*)malloc(sizeof(char) * e->width);
		j = -1;
		while (++j < e->width)
			copy[i][j] = board[i][j];
	}
	return (copy);
}

int		board_disp(t_env *e, char **board)
{
	int	i;
	int	j;

	j = -1;
	while (++j < e->height + 1)
	{
		i = -1;
		while (++i < e->width)
		{
			if (j == 0)
			{
				set_color(i);
				ft_putnbr(i % 10);
				ft_putstr(COLR_END);
			}
			else
				ft_putchar(board[j - 1][i]);
			i < e->width - 1 ? ft_putchar(' ') : 0;
		}
		ft_putchar('\n');
	}
	return (0);
}

void	set_color(int i)
{
	i /= 10;
	if (i == 0)
		return ;
	if (i % 2 == 1)
		ft_putstr(COLR_BLUE);
}
