/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:46:09 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/15 13:56:18 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	palce_exit(t_var *vars)
{
	int	index_1;
	int	index_2;

	index_1 = 0;
	index_2 = 0;
	while (index_1 < vars->map_height)
	{
		while (index_2 < vars->map_width)
		{
			if (vars->map[index_1][index_2] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->window, vars->exit, (index_2 * 165), (index_1 * 165));
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
}

int game_exit(t_var *vars)
{
	if (vars->collectible_counter == 0 )
		exit(0);
	return (1);
}
