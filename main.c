/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:18:01 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/20 22:29:36 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	vars;

	initialize_variables(&vars);
	file_checker(&vars, argc, argv);
	get_map_measure(&vars);
	initialize_map(&vars);
	map_check(&vars);
	vars.mlx = mlx_init();
	link_images(&vars);
	vars.window = mlx_new_window(vars.mlx,
			(vars.map_width * 165), (vars.map_height * 165), "Space Hunter");
	vars.image = mlx_new_image(vars.mlx,
			(vars.map_width * 165), (vars.map_height * 165));
	vars.address = mlx_get_data_addr(vars.image, &vars.bites_per_pixel,
			&vars.line_length, &vars.endian);
	xpm_to_file(&vars);
	build_background(&vars);
	palce_collectible(&vars);
	palce_walls(&vars);
	palce_player(&vars);
	palce_exit(&vars);
	mlx_hook(vars.window, 17, 1L << 0, close_image, &vars);
	mlx_key_hook(vars.window, move_player, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
