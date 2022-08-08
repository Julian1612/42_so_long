/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:08:43 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/08 10:56:07 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	link_images(t_var *vars)
{
	vars->relative_path_zero = "./images/zero.xpm";
	vars->relative_path_one = "./images/one.xpm";
	vars->relative_path_collectible = "./images/collectible.xpm";
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
