/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:22:06 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/20 14:31:52 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(t_var *vars)
{
	int	index_1;
	int	index_2;
	int	counter;

	index_1 = 0;
	index_2 = 0;
	counter = 0;
	while (index_1 < vars->map_height)
	{
		while (index_2 < vars->map_width)
		{
			if (vars->map[index_1][index_2] == 'P')
				counter ++;
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	if (counter > 1 || counter <= 0)
	{
		perror("The number of players is wrong");
		free_variables(vars);
		exit (0);
	}
	return (0);
}
