/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:07:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/23 16:04:34 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include "./libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_var {
	void	*mlx;
	void	*window;
	void	*image;
	char	*address;
	int		line_length;
	int		bites_per_pixel;
	int		endian;
	void	*one;
	void	*zero;
	char	*collectible;
	char	*exit;
	char	*player_up;
	char	*player_down;
	char	*player_left;
	char	*player_right;
	char	*relative_path_zero;
	char	*relative_path_one;
	char	*relative_path_collectible;
	char	*relative_path_exit;
	char	*relative_path_player_up;
	char	*relative_path_player_down;
	char	*relative_path_player_left;
	char	*relative_path_player_right;
	int		player_width;
	int		player_height;
	int		map_height;
	int		map_width;
	int		collectible_width;
	int		collectible_height;
	char	**map;
	int		moves;
	int		collectible_counter;
	int		collcetibles_beginning;
	int		player_direction;
	int		argc;
	char	**argv;

}	t_var;

void	get_map_measure(t_var	*vars);
void	xpm_to_file(t_var *vars);
void	link_images(t_var *vars);
int		move_player(int keycode, t_var *vars);
void	build_background(t_var *vars);
void	palce_player(t_var *vars);
void	palce_collectible(t_var *vars);
void	initialize_map(t_var *vars);
void	palce_walls(t_var *vars);
void	palce_exit(t_var *vars);
void	new_render(t_var *vars);
int		move_up(t_var *vars);
int		move_down(t_var *vars);
int		move_left(t_var *vars);
int		move_right(t_var *vars);
int		count_collectibles(t_var *vars);
int		game_exit(t_var *vars);
void	map_check(t_var *vars);
int		check_top(t_var *vars);
int		check_ground(t_var *vars);
int		check_left(t_var *vars);
int		check_right(t_var *vars);
int		check_player(t_var *vars);
int		check_exit(t_var *vars);
int		check_collectible(t_var *vars);
int		close_image(int keycode, t_var *vars);
void	free_variables(t_var *vars);
void	initialize_variables(t_var *vars);
void	put_image(t_var *vars, int index_1, int index_2);
void	move_up_update(t_var *vars, int index_1, int index_2);
void	move_down_update(t_var *vars, int index_1, int index_2);
void	move_left_update(t_var *vars, int index_1, int index_2);
void	move_right_update(t_var *vars, int index_1, int index_2);
int		check_invalid_character(t_var *vars);
void	file_checker(t_var *vars, int argc, char **argv);
void	fd_check(int fd);

#endif
