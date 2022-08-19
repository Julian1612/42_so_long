/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:38:41 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/19 13:12:40 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_var *vars)
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
				if (vars->map[index_1 - 1][index_2]
					== 'E' && game_exit(vars) == 1)
					return (1);
				if (vars->map[index_1 - 1][index_2] == '1')
					return (1);
				move_up_update(vars, index_1, index_2);
				return (1);
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	return (1);
}

void	move_up_update(t_var *vars, int index_1, int index_2)
{
	vars->map[index_1 - 1][index_2] = 'P';
	vars->map[index_1][index_2] = '0';
}

int	move_down(t_var *vars)
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
				if (vars->map[index_1 + 1][index_2]
					== 'E' && game_exit(vars) == 1)
					return (2);
				if (vars->map[index_1 + 1][index_2] == '1')
					return (2);
				move_down_update(vars, index_1, index_2);
				return (2);
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	return (2);
}

void	move_down_update(t_var *vars, int index_1, int index_2)
{
	vars->map[index_1 + 1][index_2] = 'P';
	vars->map[index_1][index_2] = '0';
}
