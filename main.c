/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:18:01 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/05 02:21:08 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_var	vars;

	vars.mlx = mlx_init();
	link_images(&vars);
	vars.window
		= mlx_new_window(vars.mlx, get_length(), get_height(), "Space Hunter");
	vars.image = mlx_new_image(vars.mlx, get_length(), get_height());
	vars.address = mlx_get_data_addr(vars.image, &vars.bites_per_pixel,
			&vars.line_length, &vars.endian);
	xpm_to_file(&vars);
	mlx_put_image_to_window(vars.mlx, vars.window, vars.image, 0, 0);
	build_map(&vars);
	mlx_key_hook(vars.window, move_player, &vars);
	printf("1hi\n");
	mlx_loop(vars.mlx);
	return (0);
}

void	link_images(t_var *vars) // die funktion mus shier raus
{
	vars->relative_path_zero = "./images/zero.xpm";
	vars->relative_path_one = "./images/one.xpm";
	vars->relative_path_collectible = "./images/collectible.xpm";
	vars->relative_path_exit = "./images/exit.xpm";
	vars->relative_path_one = "./images/one.xpm";
	vars->relative_path_player = "./images/player.xpm";
}
