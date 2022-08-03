/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:07:59 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/03 16:19:56 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
////////////////////
# include <stdio.h>
////////////////////

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
}	t_var;

void	build_map(void);
void	build_window(void);
void	put_pictures(void);
void	build_background(t_var *vars);

#endif
