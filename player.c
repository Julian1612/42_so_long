/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:27:10 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/19 15:11:20 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				put_image(vars, index_1, index_2);
				return ;
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
}

void	put_image(t_var *vars, int index_1, int index_2)
{
	if (vars->player_direction == 1)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player_up, (index_2 * 165), (index_1 * 165));
	if (vars->player_direction == 2)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player_down, (index_2 * 165), (index_1 * 165));
	if (vars->player_direction == 3)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player_left, (index_2 * 165), (index_1 * 165));
	if (vars->player_direction == 4)
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player_right, (index_2 * 165), (index_1 * 165));
}

int	move_player(int keycode, t_var *vars)
{
	vars->collectible_counter = count_collectibles(vars);
	if (keycode != 13 && keycode != 1
		&& keycode != 0 && keycode != 2 && keycode != 53)
	{
		new_render(vars);
		return (0);
	}
	if (keycode == 53)
	{
		system("leaks so_long.a");
		exit(0);
	}
	vars->moves += 1;
	ft_printf("%d\n", vars->moves);
	if (keycode == 13)
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
