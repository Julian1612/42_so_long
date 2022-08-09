/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:27:10 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/08 14:37:01 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// W: 13
// A: 0
// S: 1
// D: 2

void	palce_player(t_var *vars)
{
	int		fd;
	int		index;
	char	*line;

	fd = open("./map/map.ber", O_RDONLY);
	vars->player_width = 0;
	vars->player_height = 0;
	index = 0;
	while (vars->player_height < vars->map_height)
	{
		line = get_next_line(fd);
		while (vars->player_width < vars->map_width)
		{
			if (line[index] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->window, vars->player_up, vars->player_width, vars->player_height);
				return ;
			}
			vars->player_width += 165;
			index ++;
		}
		vars->player_width = 0;
		index = 0;
		vars->player_height += 165;
		free(line);
	}
	close(fd);
}

int	move_player(int keycode, t_var *vars)
{
	if (keycode == 0 || keycode == 123 || keycode == 1 || keycode == 125 || keycode == 2 || keycode == 124 || keycode == 13 || keycode == 126)
		build_background(vars);
	if (vars->player_height != vars->collectible_height || vars->player_width != vars->collectible_width)
		palce_collectible(vars);
	if (keycode == 0 || keycode == 123)
	{
		vars->player_width -= 165;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player_left, vars->player_width, vars->player_height);
	}
	if (keycode == 1 || keycode == 125)
	{
		vars->player_height += 165;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player_down, vars->player_width, vars->player_height);
	}
	if (keycode == 2 || keycode == 124)
	{
		vars->player_width += 165;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player_right, vars->player_width, vars->player_height);
	}
	if (keycode == 13 || keycode == 126)
	{
		vars->player_height -= 165;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player_up, vars->player_width, vars->player_height);
	}
	return (0);
}
