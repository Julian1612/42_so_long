/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:08:43 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/20 21:53:56 by jschneid         ###   ########.fr       */
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
	vars->player_up = mlx_xpm_file_to_image(vars->mlx,
			vars->relative_path_player_up,
			&image_width, &image_height);
	vars->player_down = mlx_xpm_file_to_image(vars->mlx,
			vars->relative_path_player_down,
			&image_width, &image_height);
	vars->player_left = mlx_xpm_file_to_image(vars->mlx,
			vars->relative_path_player_left,
			&image_width, &image_height);
	vars->player_right = mlx_xpm_file_to_image(vars->mlx,
			vars->relative_path_player_right,
			&image_width, &image_height);
}

void	map_check(t_var *vars)
{
	check_player(vars);
	check_collectible(vars);
	check_exit(vars);
	if (check_invalid_character(vars) == 1)
	{
		perror("There is a invalid character in the map");
		free_variables(vars);
		exit (0);
	}
	if (check_top(vars) == 1 || check_ground(vars) == 1
		|| check_left(vars) == 1 || check_right(vars) == 1)
	{
		perror("The map must be closed/surrounded by walls");
		free_variables(vars);
		exit (0);
	}
}

int	check_invalid_character(t_var *vars)
{
	int	index_1;
	int	index_2;

	index_1 = 0;
	index_2 = 0;
	while (index_1 < vars->map_height)
	{
		while (index_2 < vars->map_width)
		{
			if (vars->map[index_1][index_2] != '0'
				&& vars->map[index_1][index_2] != '1'
				&& vars->map[index_1][index_2] != 'E'
				&& vars->map[index_1][index_2] != 'P'
				&& vars->map[index_1][index_2] != 'C')
				return (1);
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	return (0);
}

int	check_collectible(t_var *vars)
{
	int	index_1;
	int	index_2;
	int	counter;

	index_1 = 0;
	index_2 = 0;
	counter = 0;
	while (index_1 < vars->map_height)
	{
		while (index_2 < vars->map_width)
		{
			if (vars->map[index_1][index_2] == 'C')
				counter ++;
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	if (counter <= 0)
	{
		perror("The number of collectibles is wrong");
		free_variables(vars);
		exit (0);
	}
	return (0);
}
