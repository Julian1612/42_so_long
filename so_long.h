/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:07:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/17 11:17:17 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include "./libft/libft.h"
////////////////////
# include <stdio.h>
////////////////////

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

}	t_var;

void	build(void);
void	build_window(void);
void	put_pictures(void);
void	build_map(t_var *vars);
char	*get_next_line(int fd);
char	*get_buffer(char *buffer, int fd);
char	*cut_buffer(char *buffer, char **line);
void	get_map_measure(t_var	*vars);
void	build_map(t_var *vars);
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

#endif
