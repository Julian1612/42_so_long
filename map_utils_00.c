/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:31:50 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/19 19:13:51 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(t_var *vars)
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
			if (vars->map[index_1][index_2] == 'E')
				counter ++;
			index_2 ++;
		}
		index_2 = 0;
		index_1 ++;
	}
	if (counter <= 0)
	{
		perror("The number of exits is wrong");
		exit (0);
	}
	return (0);
}

int	check_top(t_var *vars)
{
	int	index;

	index = 0;
	while (vars->map[0][index] != '\0')
	{
		if (vars->map[0][index] != '1')
			return (1);
		index ++;
	}
	return (0);
}

int	check_ground(t_var *vars)
{
	int	index;

	index = 0;
	while (vars->map[vars->map_height -1][index] != '\0')
	{
		if (vars->map[(vars->map_height - 1)][index] != '1')
			return (1);
		index ++;
	}
	return (0);
}

int	check_left(t_var *vars)
{
	int	index;

	index = 0;
	while (index < vars->map_height)
	{
		if (vars->map[index][0] != '1')
			return (1);
		index ++;
	}
	return (0);
}

int	check_right(t_var *vars)
{
	int	index;

	index = 0;
	while (index < vars->map_height)
	{
		if (vars->map[index][(vars->map_width - 1)] != '1')
			return (1);
		index ++;
	}
	return (0);
}
