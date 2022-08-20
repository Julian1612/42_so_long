/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:08:45 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/20 22:13:40 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_image(int keycode, t_var *vars)
{
	(void) keycode;
	(void) vars;
	exit (0);
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

	fd = open(vars->argv[1], O_RDONLY);
	fd_check(fd);
	line = get_next_line(fd);
	vars->map_width = (ft_strlen(line) - 1);
	while (line != NULL)
	{
		if (ft_strlen(line) - 1 != (size_t) vars->map_width)
		{
			perror("The map is not a rectangular");
			exit (0);
		}
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

	fd = open(vars->argv[1], O_RDONLY);
	fd_check(fd);
	vars->map = (char **) malloc((vars->map_height + 1) * sizeof(char *));
	index = 0;
	while (index < vars->map_height)
	{
		vars->map[index] = (char *)malloc((vars->map_width + 1) * sizeof(char));
		if (vars->map == NULL)
		{
			free (vars->map);
			close (0);
		}
		vars->map[index][(vars->map_width + 1) - 1] = '\0';
		line = get_next_line(fd);
		ft_strlcpy(vars->map[index], line, (vars->map_width + 1));
		free(line);
		index++;
	}
	close(fd);
	vars->map[vars->map_height] = NULL;
}

void	initialize_variables(t_var *vars)
{
	vars->moves = 0;
	vars->player_direction = 1;
	vars->collectible_counter = 0;
	vars->collcetibles_beginning = 0;
	vars->collcetibles_beginning = count_collectibles(vars);
	vars->map_height = 1;
}

void	fd_check(int fd)
{
	if (fd == -1)
	{
		perror("File not found");
		exit (0);
	}
}
