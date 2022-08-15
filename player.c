/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:27:10 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/15 14:20:52 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// W: 13
// A: 0
// S: 1
// D: 2

void	palce_player(t_var *vars)
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
				if (vars->player_direction == 1)
					mlx_put_image_to_window(vars->mlx, vars->window, vars->player_up, (index_2 * 165), (index_1 * 165));
				if (vars->player_direction == 2)
					mlx_put_image_to_window(vars->mlx, vars->window, vars->player_down, (index_2 * 165), (index_1 * 165));
				if (vars->player_direction == 3)
					mlx_put_image_to_window(vars->mlx, vars->window, vars->player_left, (index_2 * 165), (index_1 * 165));
				if (vars->player_direction == 4)
					mlx_put_image_to_window(vars->mlx, vars->window, vars->player_right, (index_2 * 165), (index_1 * 165));
				return ;
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
}

int	move_player(int keycode, t_var *vars)
{
	vars->moves += 1;
	vars->collectible_counter = count_collectibles(vars);
	printf("collectibles: %d available: %d\n", vars->collcetibles_beginning, vars->collectible_counter); // use my printf !!
	printf("%d\n", vars->moves); // use my printf !!
	if (keycode != 13 && keycode != 1 && keycode != 0 && keycode != 2)
	{
		new_render(vars);
		return (0);
	}
	else if (keycode == 13)
		vars->player_direction = move_up(vars);
	else if (keycode == 1)
		vars->player_direction = move_down(vars);
	else if (keycode == 0)
		vars->player_direction = move_left(vars);
	else if (keycode == 2)
		vars->player_direction = move_right(vars);
	new_render(vars);
	return (0);
}

void	new_render(t_var *vars)
{
	build_background(vars);
	palce_collectible(vars);
	palce_walls(vars);
	palce_player(vars);
	palce_exit(vars);
}

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
				if (vars->map[index_1 - 1][index_2] == 'E' && game_exit(vars) == 1)
					return (1);
				if (vars->map[index_1 - 1][index_2] == '1')
					return (1);
				vars->map[index_1 - 1][index_2] = 'P';
				vars->map[index_1][index_2] = '0';
				return (1);
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	return (1);
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
				if (vars->map[index_1 + 1][index_2] == 'E' && game_exit(vars) == 1)
					return (2);
				if (vars->map[index_1 + 1][index_2] == '1')
					return (2);
				vars->map[index_1 + 1][index_2] = 'P';
				vars->map[index_1][index_2] = '0';
				return (2);
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	return (2);
}

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
				if (vars->map[index_1][index_2 - 1] == 'E' && game_exit(vars) == 1)
					return (3);
				if (vars->map[index_1][index_2 - 1] == '1')
					return (3);
				vars->map[index_1][index_2 - 1] = 'P';
				vars->map[index_1][index_2] = '0';
				return (3);
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	return (3);
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
				if (vars->map[index_1][index_2 + 1] == 'E' && game_exit(vars) == 1)
					return (4);
				if (vars->map[index_1][index_2 + 1] == '1')
					return (4);
				vars->map[index_1][index_2 + 1] = 'P';
				vars->map[index_1][index_2] = '0';
				return (4);
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	return (4);
}
