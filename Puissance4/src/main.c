/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:03:42 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/28 21:33:13 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		main(int argc, char **argv)
{
	t_env e;

	if (args_get(&e, argc, argv) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (board_create(&e) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	game_loop(&e);
	return (0);
}

int		args_get(t_env *e, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (-1);
	e->w = ft_atof(argv[1]);
	e->h = ft_atof(argv[2]);
	while (argv[++i])
	{
		if (str_isdigit(argv[i]) == -1)
			return (-1);
		argv[i]++;
	}
	if (e->w < 7 || e->w > MAX_INT ||
		e->h < 6 || e->h > MAX_INT)
		return (-1);
	e->w > 100 ? e->w = 100 : 0;
	e->h > 100 ? e->h = 100 : 0;
	return (0);
}

int		str_isdigit(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (-1);
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
