/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:06:35 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/04 18:07:18 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(void)
{
	int	fd;
	int	width;

	width = 0;
	fd = open("./map/map.ber", O_RDONLY);
	while (get_next_line(fd))
		width += 165;
	close (fd);
	return (width);
}

int	get_length(void)
{
	int	fd;
	int	length;

	fd = open("./map/map.ber", O_RDONLY);
	length = 165 * (ft_strlen(get_next_line(fd)) - 1);
	close(fd);
	return (length);
}
