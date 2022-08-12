/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:57:45 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/11 17:00:59 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	palce_collectible(t_var *vars)
{
	int	index_1;
	int	index_2;

	index_1 = 0;
	index_2 = 0;
	while (index_1 < vars->map_height)
	{
		while (index_2 < vars->map_width)
		{
			if (vars->map[index_1][index_2] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->window, vars->collectible, (index_2 * 165), (index_1 * 165));
				vars->collectible_counter += 1;
			}
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
}

int	count_collectibles(t_var *vars)
{
	int	index_1;
	int	index_2;
	int	collectibles;

	index_1 = 0;
	index_2 = 0;
	collectibles = 0;
	while (index_1 < vars->map_height)
	{
		while (index_2 < vars->map_width)
		{
			if (vars->map[index_1][index_2] == 'C')
				collectibles += 1;
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	return (collectibles);
}
