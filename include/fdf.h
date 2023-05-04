/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:58:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/04/09 15:37:32 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "keycode.h"

# define GRID 0x00dddd
# define STD_Z 0x990000

# define CTRL_WIDTH 200
# define WIN_WIDTH 1280
# define WIN_HEIGHT 640

# define ISOMETRIC 1
# define ORTHOGRAPHIC 2

typedef struct s_alt
{
	int	z;
	int	color;
}	t_alt;

typedef struct s_cache
{
	double	alpha;
	double	cos_alpha;
	double	sin_alpha;
	double	beta;
	double	cos_beta;
	double	sin_beta;
	double	gamma;
	double	cos_gamma;
	double	sin_gamma;
}	t_cache;

typedef struct s_scene
{
	int		rows;
	int		cols;
	int		scale;
	int		scaled_row;
	int		scaled_col;
	int		std_scale;
	int		view;
	float	z_scale;
	float	std_z;
	int		move_x;
	int		move_y;
	int		mid_width;
	int		mid_height;
	t_cache	cache;
	t_alt	**map;
}	t_scene;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		x;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	rgb[3];
}	t_point;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	canvas;
	t_img	legend;
	t_bool	show_legend;
	t_scene	scene;
}	t_mlx;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	ix;
	int	iy;
	int	err;
	int	e1;
	int	e2;
	int	pos;
	int	len;
}	t_line;

void	load_map(t_scene *scene, char *file);
void	draw_line(const t_img *canvas, t_point p1, t_point p2);
void	put_pixel(const t_img *canvas, int x, int y, int color);
void	data_convert(t_scene *scene, int fd);
void	generate_map(t_scene *scene);
void	destroy_map(t_scene *scene);
void	event_handler(t_mlx *data);

void	init_scene(t_mlx *data);
void	draw_scene(t_mlx *data);
void	resize(t_mlx *data);
int		reset_scene(t_scene *scene);
void	set_rotation(t_cache *cache);
void	rotate(t_point *p, const t_cache *cache);
void	set_scale(t_scene *scene);
int		get_scale(t_mlx *data);
int		quit(t_mlx *data);

/* Transformations */
int		translate(int keysym, t_scene *scene);
int		rotate_x(int keysym, t_scene *scene);
int		rotate_y(int keysym, t_scene *scene);
int		rotate_z(int keysym, t_scene *scene);
int		zoom(int keysym, t_scene *scene);
void	render_background(t_img *image, int color);
void	show_controls(t_mlx *data);
int		redraw(t_mlx *data);

#endif
