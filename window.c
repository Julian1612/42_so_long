/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:08:45 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/15 19:57:11 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_window(void)
{
	t_var	vars;

	get_map_measure(&vars);
	initialize_map(&vars);
	map_check(&vars);
	vars.moves = 0;
	vars.player_direction = 1;
	vars.collectible_counter = 0;
	vars.collcetibles_beginning = 0; // kann man in einer function inizialiseiren
	vars.collcetibles_beginning = count_collectibles(&vars);
	vars.mlx = mlx_init();
	link_images(&vars);
	vars.window = mlx_new_window(vars.mlx, (vars.map_width * 165), (vars.map_height * 165), "Space Jamming");
	vars.image = mlx_new_image(vars.mlx, (vars.map_width * 165), (vars.map_height * 165));
	vars.address = mlx_get_data_addr(vars.image, &vars.bites_per_pixel,
			&vars.line_length, &vars.endian);
	xpm_to_file(&vars);
	build_background(&vars);
	palce_collectible(&vars);
	palce_walls(&vars);
	palce_player(&vars);
	palce_exit(&vars);
	mlx_key_hook(vars.window, move_player, &vars);
	mlx_loop(vars.mlx);
}

void	build_background(t_var *vars)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (height < (vars->map_height * 165))
	{
		while (width < (vars->map_width * 165))
		{
			mlx_put_image_to_window(vars->mlx, vars->window, vars->zero, width, height);
			width += 165;
		}
		width = 0;
		height += 165;
	}
}

void	get_map_measure(t_var *vars)
{
	int		fd;
	char	*line;

	fd = open("./map/map.ber", O_RDONLY);
	vars->map_height = 1;
	line = get_next_line(fd);
	while (get_next_line(fd))
		vars->map_height += 1;
	vars->map_width = (ft_strlen(line) - 1);
	close (fd);
}

void	initialize_map(t_var *vars)
{
	int		index;
	int		fd;
	char	*line;
	int		x;
	int		y;

	fd = open("./map/map.ber", O_RDONLY);
	x = vars->map_height;
	y = (vars->map_width + 1);
	vars->map = (char **) malloc(x * sizeof(char *));
	index = 0;
	while (index < x)
	{
		vars->map[index] = (char *) malloc(y * sizeof(char));
		line = get_next_line(fd);
		ft_strlcpy(vars->map[index], line, y);
		free(line);
		index ++;
	}
	close(fd);
	vars->map[x] = NULL;
}
