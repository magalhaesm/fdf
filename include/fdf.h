/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:58:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/25 08:46:54 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "../libft/libft.h"

# define GRID 0x00FFFF
# define CANVAS_BG 0x000000

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 600

typedef struct s_alt
{
	int	z;
	int	color;
}	t_alt;

typedef struct s_scene
{
	int		rows;
	int		cols;
	int		scale;
	int		scaled_row;
	int		scaled_col;
	int		mid_width;
	int		mid_height;
	t_alt	**map;
}	t_scene;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	canvas;
	t_scene	scene;
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

void	load_map(t_scene *scene, char *file);
void	render_background(t_img *canvas, int color);
void	draw_line(t_img *canvas, t_point p1, t_point p2, int color);
void	put_pixel(t_img *canvas, int x, int y, int color);
void	free_map(t_scene *scene);
void	scene_init(t_data *data);
int		get_scale(int row, int col);
void	render_scene(t_data *data);
int		quit(int keysym, t_data *data);
void	data_convert(t_scene *scene, int fd);
void	generate_map(t_scene *scene);

#endif
