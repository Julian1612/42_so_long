/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:27:46 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/10 19:08:05 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	palce_walls(t_var *vars)
{
	int	index_1;
	int	index_2;

	index_1 = 0;
	index_2 = 0;
	while (index_1 < vars->map_height)
	{
		while (index_2 < (vars->map_width + 1))
		{
			if (vars->map[index_1][index_2] == '1')
				mlx_put_image_to_window(vars->mlx, vars->window, vars->one, (index_2 * 165), (index_1 * 165));
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
}
