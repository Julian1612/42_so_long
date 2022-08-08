/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:57:45 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/08 11:36:24 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	palce_collectible(t_var *vars)
{
	int		fd;
	int		index;
	char	*line;

	fd = open("./map/map.ber", O_RDONLY);
	vars->collectible_height = 0;
	vars->collectible_width = 0;
	index = 0;
	while (vars->collectible_height < vars->map_height)
	{
		line = get_next_line(fd);
		while (vars->collectible_width < vars->map_width)
		{
			if (line[index] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->window, vars->collectible, vars->collectible_width, vars->collectible_height);
				return ;
			}
			vars->collectible_width += 165;
			index ++;
		}
		vars->collectible_width = 0;
		index = 0;
		vars->collectible_height += 165;
		free(line);
	}
	close(fd);
}
