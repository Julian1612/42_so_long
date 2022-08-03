/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:08:43 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/03 16:50:55 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_map(void)
{
	build_window();
}

void	build_window(void)
{
	t_var	vars;
	char	*relative_path_zero;
	char	*relative_path_one;
	int		image_zero_width;
	int		image_zero_height;
	int		image_one_width;
	int		image_one_height;

	relative_path_zero = "/Users/jschneid/42/so_long/42_so_long/images/zero.xpm";
	relative_path_one = "/Users/jschneid/42/so_long/42_so_long/images/one.xpm";
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 1980, 990, "Space");
	vars.image = mlx_new_image(vars.mlx, 1980, 990);
	vars.address = mlx_get_data_addr(vars.image, &vars.bites_per_pixel,
			&vars.line_length, &vars.endian);
	vars.zero = mlx_xpm_file_to_image(vars.mlx, relative_path_zero, &image_zero_width, &image_zero_height);
	vars.one = mlx_xpm_file_to_image(vars.mlx, relative_path_one, &image_one_width, &image_one_height);
	mlx_put_image_to_window(vars.mlx, vars.window, vars.image, 0, 0);
	build_background(&vars);
	mlx_loop(vars.mlx);
}

// Mit gnl the file bis zum ende lesen daraus kann man dann die breite und hohe der map bekommen und es kann
// gleichzeitig noch der hintergrund (sterne) erstellt werden
// dann ruft man noch fur walls, collectibales, exits etc die map .ber file seperat auf legt alles nach
// und nach uebernander

void	build_background(t_var *vars)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (height < 990)
	{
		while (width < 1980)
		{
			mlx_put_image_to_window(vars->mlx, vars->window, vars->zero, width, height);
			width += 165;
		}
		width = 0;
		height += 165;
	}
}

void	put_walls(t_var *vars)
{

}
