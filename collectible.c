/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:57:45 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/09 20:46:39 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	palce_collectible(t_var *vars)
{
	int	index_1;
	int	index_2;

	index_1 = 0;
	index_2 = 0;
	while (index_1 < (vars->map_width / 165))
	{
		while (index_2 < (vars->map_height / 165))
		{
			printf("%c", vars->map[index_1][index_2]);
			if (vars->map[index_1][index_2] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->window, vars->collectible, 0, 0);
			index_2 ++;
		}
		index_1 ++;
	}
}

	// int		fd;
	// int		index;
	// char	*line;

	// fd = open("./map/map.ber", O_RDONLY);
	// vars->collectible_height = 0;
	// vars->collectible_width = 0;
	// index = 0;
	// while (vars->collectible_height < vars->map_height)
	// {
	// 	line = get_next_line(fd);
	// 	while (vars->collectible_width < vars->map_width)
	// 	{
	// 		if (line[index] == 'C')
	// 		{
	// 			mlx_put_image_to_window(vars->mlx, vars->window, vars->collectible, vars->collectible_width, vars->collectible_height);
	// 		}
	// 		vars->collectible_width += 165;
	// 		index ++;
	// 	}
	// 	vars->collectible_width = 0;
	// 	index = 0;
	// 	vars->collectible_height += 165;
	// 	free(line);
	// }
	// close(fd);
