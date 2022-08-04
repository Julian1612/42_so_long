/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:08:43 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/04 17:52:51 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_window(void)
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
	mlx_loop(vars.mlx);
}

void	link_images(t_var *vars)
{
	vars->relative_path_zero
		= "./images/zero.xpm";
	vars->relative_path_one
		= "./images/one.xpm";
	vars->relative_path_collectible
		= "./images/collectible.xpm";
	vars->relative_path_exit
		= "./images/exit.xpm";
	vars->relative_path_one
		= "./images/one.xpm";
	vars->relative_path_player
		= "./images/player.xpm";
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
	vars->player = mlx_xpm_file_to_image(vars->mlx, vars->relative_path_player,
			&image_width, &image_height);
}

int	get_height(void)
{
	int	fd;
	int	width;

	width = 0;
	fd = open("./map/map.ber", O_RDONLY);
	while (get_next_line(fd))
		width += 165;
	close (fd);
	return (width);
}

int	get_length(void)
{
	int	fd;
	int	length;

	fd = open("./map/map.ber", O_RDONLY);
	length = 165 * (ft_strlen(get_next_line(fd)) - 1);
	close(fd);
	return (length);
}

void	build_map(t_var *vars)
{
	int		fd;
	int		width;
	int		height;
	int		index;
	char	*line;

	fd = open("./map/map.ber", O_RDONLY);
	width = 0;
	height = 0;
	index = 0;
	while (height < get_height())
	{
		free(line);
		line = get_next_line(fd);
		while (width < get_length())
		{
			render_image(vars, width, height, index, line);
			width += 165;
			index ++;
		}
		width = 0;
		index = 0;
		height += 165;
	}
	close(fd);
}

void	render_image(t_var *vars, int width, int height, int index, char *line)
{
	mlx_put_image_to_window(vars->mlx, vars->window, vars->zero, width, height);
	if (line[index] == '1')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->one, width, height);
	if (line[index] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->collectible, width, height);
	if (line[index] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->exit, width, height);
	if (line[index] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->window,
			vars->player, width, height);
}
