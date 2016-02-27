/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:03:42 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/27 11:50:48 by wwatkins         ###   ########.fr       */
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
	board_disp(&e);
	game_loop(&e);
	return (0);
}

int		args_get(t_env *e, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (-1);
	e->width = ft_atof(argv[1]);
	e->height = ft_atof(argv[2]);
	while (argv[++i])
	{
		if (str_isdigit(argv[i]) == -1)
			return (-1);
		argv[i]++;
	}
	if (e->width < 7 || e->width > MAX_INT ||
		e->height < 6 || e->height > MAX_INT)
		return (-1);
	e->width > 100 ? e->width = 100 : 0;
	e->height > 100 ? e->height = 100 : 0;
	return (1);
}
