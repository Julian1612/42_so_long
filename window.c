/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:08:45 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/19 16:35:03 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_image(int keycode, t_var *vars)
{
	keycode = 5;
	system("leaks so_long.a");
	mlx_destroy_window(vars->mlx, vars->window);
	return (0);
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
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->zero, width, height);
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
	vars->map_width = (ft_strlen(line) - 1);
	while (line != NULL)
	{
		free (line);
		line = get_next_line(fd);
		if (line == NULL)
		{
			free (line);
			break ;
		}
		vars->map_height += 1;
	}
	free (line);
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
	y = vars->map_height;
	x = vars->map_width + 1;
	vars->map = (char **) malloc((y + 1) * sizeof(char *));
	index = 0;
	while (index < y)
	{
		vars->map[index] = (char *)malloc(x * sizeof(char));
		if (vars->map == NULL)
		{
			free (vars->map);
			system("leaks so_long.a");
			close (0);
		}
		vars->map[index][x - 1] = '\0';
		line = get_next_line(fd);
		ft_strlcpy(vars->map[index], line, x);
		free(line);
		index++;
	}
	close(fd);
	vars->map[y] = NULL;
}

void	initialize_variables(t_var *vars)
{
	vars->moves = 0;
	vars->player_direction = 1;
	vars->collectible_counter = 0;
	vars->collcetibles_beginning = 0;
	vars->collcetibles_beginning = count_collectibles(vars);
}
