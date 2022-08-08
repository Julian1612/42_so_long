/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:08:45 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/08 13:34:58 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_window(void)
{
	t_var	vars;

	get_map_height(&vars);
	get_map_width(&vars);
	vars.mlx = mlx_init();
	link_images(&vars);
	vars.window = mlx_new_window(vars.mlx, vars.map_width, vars.map_height, "Space Jamming");
	vars.image = mlx_new_image(vars.mlx, vars.map_width, vars.map_height);
	vars.address = mlx_get_data_addr(vars.image, &vars.bites_per_pixel,
			&vars.line_length, &vars.endian);
	xpm_to_file(&vars);
	build_background(&vars);
	palce_collectible(&vars);
	palce_player(&vars);
	mlx_key_hook(vars.window, move_player, &vars);
	mlx_loop(vars.mlx);
}

void	build_background(t_var *vars)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (height < vars->map_height)
	{
		while (width < vars->map_width)
		{
			mlx_put_image_to_window(vars->mlx, vars->window, vars->zero, width, height);
			width += 165;
		}
		width = 0;
		height += 165;
	}
}

void	get_map_height(t_var *vars)
{
	int		fd;

	vars->map_height = 0;
	fd = open("./map/map.ber", O_RDONLY);
	while (get_next_line(fd))
		vars->map_height += 165;
	close (fd);
}

void	get_map_width(t_var	*vars)
{
	int		fd;

	fd = open("./map/map.ber", O_RDONLY);
	vars->map_width = 165 * (ft_strlen(get_next_line(fd)) - 1);
	close(fd);
}
