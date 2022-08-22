/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:58:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/22 12:13:04 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"

#define CANVAS_BG 0x000000

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 600
// #define WINDOW_WIDTH 600
// #define WINDOW_HEIGHT 500

typedef struct s_scene
{
	int	**map;
	int	rows;
	int	cols;
	int	scale;
}	t_scene;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_cache
{
	int	scaled_col;
	int	scaled_row;
	int	mid_width;
	int	mid_height;
}	t_cache;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_scene	scene;
	t_img	canvas;
	t_cache	cache;
}	t_data;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	ix;
	int	iy;
	int	error;
	int	e1;
	int	e2;
	int	i;
}	t_line;

void	load_data(t_scene *scene, char *file);
void	free_map(t_scene *scene);

#endif
