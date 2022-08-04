/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:07:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/04 17:35:27 by jschneid         ###   ########.fr       */
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
#  define BUFFER_SIZE 1
# endif

typedef struct s_var {
	void	*mlx;
	void	*window;
	void	*image;
	void	*one;
	void	*zero;
	char	*address;
	int		line_length;
	int		bites_per_pixel;
	int		endian;
	char	*collectible;
	char	*exit;
	char	*player;

	char	*relative_path_zero;
	char	*relative_path_one;
	char	*relative_path_collectible;
	char	*relative_path_exit;
	char	*relative_path_player;
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
int		get_length(void);
size_t	ft_strlen(const char *a);
int		get_height(void);
void	build_map(t_var *vars);
void	put_collectible(t_var *vars, int width, int height);
void	put_wall(t_var *vars, int width, int height);
void	put_collectible(t_var *vars, int width, int height);
void	put_exit(t_var *vars, int width, int height);
void	put_player(t_var *vars, int width, int height);
void	render_image(t_var *vars, int width, int height, int index, char *line);
void	xpm_to_file(t_var *vars);
void	link_images(t_var *vars);

#endif
