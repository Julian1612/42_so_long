/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:07:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/09 14:50:33 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
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
}	t_var;

void	build(void);
void	build_window(void);
void	put_pictures(void);
void	build_map(t_var *vars);
char	*get_next_line(int fd);
char	*get_buffer(char *buffer, int fd);
char	*cut_buffer(char *buffer, char **line);
size_t	ft_strlen(const char *a);
char	*ft_strchr(char const *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
size_t	ft_strlen(const char *a);
void	get_map_height(t_var	*vars);
void	get_map_width(t_var	*vars);
void	build_map(t_var *vars);
void	xpm_to_file(t_var *vars);
void	link_images(t_var *vars);
int		move_player(int keycode, t_var *vars);
void	build_background(t_var *vars);
void	palce_player(t_var *vars);
void	palce_collectible(t_var *vars);
void	initialize_map(t_var *vars);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
