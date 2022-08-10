/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:27:10 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/10 21:04:51 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// W: 13
// A: 0
// S: 1
// D: 2

void	palce_player(t_var *vars, int direction)
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
				if (direction == 1)
					mlx_put_image_to_window(vars->mlx, vars->window, vars->player_up, (index_2 * 165), (index_1 * 165));
				if (direction == 2)
					mlx_put_image_to_window(vars->mlx, vars->window, vars->player_down, (index_2 * 165), (index_1 * 165));
				if (direction == 3)
					mlx_put_image_to_window(vars->mlx, vars->window, vars->player_left, (index_2 * 165), (index_1 * 165));
				if (direction == 4)
					mlx_put_image_to_window(vars->mlx, vars->window, vars->player_right, (index_2 * 165), (index_1 * 165));
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
}

int	move_player(int keycode, t_var *vars)
{
	int	direction;

	direction = 0;
	if (keycode == 13)
		direction = move_up(vars);
	if (keycode == 1)
		direction = move_down(vars);
	if (keycode == 0)
		direction = move_left(vars);
	if (keycode == 2)
		direction = move_right(vars);
	new_render(vars, direction);
	return (0);
}

void	new_render(t_var *vars, int direction)
{
	build_background(vars);
	palce_collectible(vars);
	palce_walls(vars);
	palce_player(vars, direction);
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

// int	move_player(int keycode, t_var *vars)
// {
// 	if (keycode == 0 || keycode == 123 || keycode == 1 || keycode == 125 || keycode == 2 || keycode == 124 || keycode == 13 || keycode == 126)
// 	{
// 		palce_collectible(vars);
// 		palce_walls(vars);
// 		palce_player(vars);
// 		palce_exit(vars);
// 	}
// 	if (vars->player_height != vars->collectible_height || vars->player_width != vars->collectible_width)
// 		palce_collectible(vars);
// 	if (keycode == 0 || keycode == 123)
// 	{
// 		vars->player_width -= 165;
// 		mlx_put_image_to_window(vars->mlx, vars->window, vars->player_left, vars->player_width, vars->player_height);
// 	}
// 	if (keycode == 1 || keycode == 125)
// 	{
// 		vars->player_height += 165;
// 		mlx_put_image_to_window(vars->mlx, vars->window, vars->player_down, vars->player_width, vars->player_height);
// 	}
// 	if (keycode == 2 || keycode == 124)
// 	{
// 		vars->player_width += 165;
// 		mlx_put_image_to_window(vars->mlx, vars->window, vars->player_right, vars->player_width, vars->player_height);
// 	}
// 	if (keycode == 13 || keycode == 126)
// 	{
// 		vars->player_height -= 165;
// 		mlx_put_image_to_window(vars->mlx, vars->window, vars->player_up, vars->player_width, vars->player_height);
// 	}
// 	return (0);
// }
