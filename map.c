/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:08:43 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/16 20:30:40 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	link_images(t_var *vars)
{
	vars->relative_path_zero = "./images/zero.xpm";
	vars->relative_path_one = "./images/one.xpm";
	vars->relative_path_collectible = "./images/collectible_DALLE.xpm";
	vars->relative_path_exit = "./images/exit.xpm";
	vars->relative_path_one = "./images/one.xpm";
	vars->relative_path_player_up = "./images/player_up.xpm";
	vars->relative_path_player_down = "./images/player_down.xpm";
	vars->relative_path_player_left = "./images/player_left.xpm";
	vars->relative_path_player_right = "./images/player_right.xpm";
}

void	xpm_to_file(t_var *vars)
{
	int		image_width;
	int		image_height;

	vars->zero = mlx_xpm_file_to_image(vars->mlx, vars->relative_path_zero,
			&image_width, &image_height);
	vars->one = mlx_xpm_file_to_image(vars->mlx, vars->relative_path_one,
			&image_width, &image_height);
	vars->collectible = mlx_xpm_file_to_image(vars->mlx,
			vars->relative_path_collectible, &image_width, &image_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, vars->relative_path_exit,
			&image_width, &image_height);
	vars->player_up = mlx_xpm_file_to_image(vars->mlx, vars->relative_path_player_up,
			&image_width, &image_height);
	vars->player_down = mlx_xpm_file_to_image(vars->mlx, vars->relative_path_player_down,
			&image_width, &image_height);
	vars->player_left = mlx_xpm_file_to_image(vars->mlx, vars->relative_path_player_left,
			&image_width, &image_height);
	vars->player_right = mlx_xpm_file_to_image(vars->mlx, vars->relative_path_player_right,
			&image_width, &image_height);
}

void	map_check(t_var *vars)
{
	if (check_top(vars) == 1 || check_ground(vars) == 1 || check_left(vars) == 1 || check_right(vars) == 1)
	{
		perror("The map must be closed/surrounded by walls");
		exit (0);
	}
}

int	check_top(t_var *vars)
{
	int	index;

	index = 0;
	while (vars->map[0][index] != '\0')
	{
		if (vars->map[0][index] != '1')
			return (1);
		index ++;
	}
	return (0);
}

int	check_ground(t_var *vars)
{
	int	index;

	index = 0;
	while (vars->map[vars->map_height -1][index] != '\0')
	{
		if (vars->map[(vars->map_height - 1)][index] != '1')
			return (1);
		index ++;
	}
	return (0);
}

int	check_left(t_var *vars)
{
	int	index;

	index = 0;
	while (index < vars->map_height)
	{
		if (vars->map[index][0] != '1')
			return (1);
		index ++;
	}
	return (0);
}

int	check_right(t_var *vars)
{
	int	index;

	index = 0;
	while (index < vars->map_height)
	{
		if (vars->map[index][(vars->map_width - 1)] != '1')
			return (1);
		index ++;
	}
	return (0);
}
