/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:16:11 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/19 12:41:01 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_var *vars)
{
	int	index_1;
	int	index_2;

	index_1 = 0;
	index_2 = 0;
	while (index_1 < vars->map_height)
	{
		while (index_2 < vars->map_width)
		{
			if (vars->map[index_1][index_2] == 'P')
			{
				if (vars->map[index_1][index_2 - 1]
					== 'E' && game_exit(vars) == 1)
					return (3);
				if (vars->map[index_1][index_2 - 1] == '1')
					return (3);
				move_left_update(vars, index_1, index_2);
				return (3);
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	return (3);
}

void	move_left_update(t_var *vars, int index_1, int index_2)
{
	vars->map[index_1][index_2 - 1] = 'P';
	vars->map[index_1][index_2] = '0';
}

int	move_right(t_var *vars)
{
	int	index_1;
	int	index_2;

	index_1 = 0;
	index_2 = 0;
	while (index_1 < vars->map_height)
	{
		while (index_2 < vars->map_width)
		{
			if (vars->map[index_1][index_2] == 'P')
			{
				if (vars->map[index_1][index_2 + 1]
					== 'E' && game_exit(vars) == 1)
					return (4);
				if (vars->map[index_1][index_2 + 1] == '1')
					return (4);
				move_right_update(vars, index_1, index_2);
				return (4);
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	return (4);
}

void	move_right_update(t_var *vars, int index_1, int index_2)
{
	vars->map[index_1][index_2 + 1] = 'P';
	vars->map[index_1][index_2] = '0';
}
