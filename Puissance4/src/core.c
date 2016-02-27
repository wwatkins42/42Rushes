/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:11:40 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/27 14:08:31 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		game_loop(t_env *e)
{
	int	random;

	e->game = 1;
	srand(time(NULL));
	random = (rand() % 2);
//	if (random)
//	{
		turn_player(e);
//		turn_ia(e);
//	}
//	else
//		turn_ia(e);
	while (e->game)
	{
		turn_player(e);
		turn_ia(e);
	}
	return (0);
}

int		turn_player(t_env *e)
{
	get_input(e);
	board_insert(e, HUMAN);
	board_disp(e);
	check_win(e, HUMAN);
	return (0);
}

int		turn_ia(t_env *e)
{
//	ai_algorithm();
	board_insert(e, AI);
	board_disp(e);
	check_win(e, AI);
	return (0);
}

int		get_input(t_env *e)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		e->input = ft_atoi(line);
		if (str_isdigit(line) == -1 || e->input < 0 || e->input > e->width - 1)
		{
			ft_putstr("invalid input\n");
			ft_strdel(&line);
		}
		else
			break ;
	}
	ft_strdel(&line);
	return (0);
}
