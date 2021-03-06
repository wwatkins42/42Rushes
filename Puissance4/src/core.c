/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:11:40 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/28 22:13:52 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		game_loop(t_env *e)
{
	int	random;

	srand(time(NULL));
	random = (rand() % 2);
	board_disp(e);
	if (random)
	{
		turn_player(e);
		turn_ia(e);
	}
	else
		turn_ia(e);
	while (1)
	{
		if (turn_player(e) == 1)
			return (0);
		if (turn_ia(e) == 1)
			return (0);
	}
	return (0);
}

int		turn_player(t_env *e)
{
	get_input(e);
	board_insert(e, e->input, 1);
	e->counter_hu--;
	if (check_win(e, 1) == 1)
	{
		disp_win(e, HUMAN);
		return (1);
	}
	if (board_complete(e) == 1 || (e->counter_ai == 0 && e->counter_hu == 0 &&
		check_win(e, 1) == 0))
	{
		disp_win(e, NONE);
		return (1);
	}
	board_disp(e);
	return (0);
}

int		turn_ia(t_env *e)
{
	board_insert(e, minimax(e, MAX_DEPTH), 2);
	e->counter_ai--;
	if (check_win(e, 2) == 1)
	{
		disp_win(e, AI);
		return (1);
	}
	if (board_complete(e) == 1 || (e->counter_ai == 0 && e->counter_hu == 0 &&
		check_win(e, 2) == 0))
	{
		disp_win(e, NONE);
		return (1);
	}
	board_disp(e);
	return (0);
}

int		get_input(t_env *e)
{
	char	*line;

	ft_putendl("- Choose a column:");
	while (get_next_line(0, &line) > 0)
	{
		e->input = ft_atoi(line);
		if (str_isdigit(line) == -1 || e->input < 0 || e->input > e->w - 1 ||
			e->board[0][e->input] != '.')
		{
			ft_putstr("invalid input\n");
			ft_putendl("- Choose a column:");
			ft_strdel(&line);
		}
		else
			break ;
	}
	ft_strdel(&line);
	return (0);
}

void	disp_win(t_env *e, int player)
{
	board_disp(e);
	if (player == HUMAN)
		ft_putendl("___ You win ! ___");
	if (player == AI)
		ft_putendl("___ Computer wins ! ___");
	if (player == NONE)
		ft_putendl("___ No winner ! ___");
}
