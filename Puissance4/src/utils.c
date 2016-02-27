/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:34:27 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/27 11:44:21 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		board_create(t_env *e)
{
	int	i;
	int	j;

	i = -1;
	if ((e->board = (int**)malloc(sizeof(int*) * e->height)) == NULL)
		return (-1);
	while (++i < e->height)
	{
		if ((e->board[i] = (int*)malloc(sizeof(int) * e->width)) == NULL)
			return (-1);
		j = -1;
		while (++j < e->width)
			e->board[i][j] = 0;
	}
	return (0);
}

int		board_disp(t_env *e)
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
			{
				e->board[j - 1][i] == 0 ? ft_putchar('.') : 0;
				e->board[j - 1][i] == 1 ? ft_putchar('O') : 0;
				e->board[j - 1][i] == 2 ? ft_putchar('X') : 0;
			}
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

int		str_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (-1);
	return (0);
}
