/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:09:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/25 15:44:40 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#define SIN_30 0.500000
#define COS_30 0.866025

static void	set_point(int row, int col, t_point *p, t_scene scene);
static void	isometric(t_point *p);

void	scene_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		WINDOW_WIDTH, WINDOW_HEIGHT, "Fil de Fer");
	data->canvas.img_ptr = mlx_new_image(data->mlx_ptr, \
		WINDOW_WIDTH, WINDOW_HEIGHT);
	data->canvas.addr = mlx_get_data_addr(data->canvas.img_ptr, \
		&data->canvas.bpp, &data->canvas.line_len, &data->canvas.endian);
	render_background(&data->canvas, CANVAS_BG);
}

void	render_scene(t_data *data)
{
	int		col;
	int		row;
	t_point	p1;
	t_point	p2;

	row = -1;
	while (++row < data->scene.rows)
	{
		col = -1;
		while (++col < data->scene.cols)
		{
			if (col + 1 < data->scene.cols)
			{
				set_point(row, col, &p1, data->scene);
				set_point(row, col + 1, &p2, data->scene);
				draw_line(&data->canvas, p1, p2, GRID);
			}
			if (row + 1 < data->scene.rows)
			{
				set_point(row, col, &p1, data->scene);
				set_point(row + 1, col, &p2, data->scene);
				draw_line(&data->canvas, p1, p2, GRID);
			}
		}
	}
}

static void	set_point(int row, int col, t_point *p, t_scene scene)
{
	p->x = col * scene.scale;
	p->y = row * scene.scale;
	p->x -= scene.scaled_col;
	p->y -= scene.scaled_row;
	p->z = scene.map[row][col].z * scene.scale * 0.5;
	isometric(p);
	p->x += scene.mid_width;
	p->y += scene.mid_height;
}

static void	isometric(t_point *p)
{
	int	temp_x;

	temp_x = p->x;
	p->x = (temp_x - p->y) * COS_30;
	p->y = (temp_x + p->y) * SIN_30 - p->z;
}

int	get_scale(int row, int col)
{
	int	scale;
	int	area;

	area = WINDOW_WIDTH * WINDOW_HEIGHT / 4;
	scale = area / (row * col);
	scale = sqrt(scale);
	if (scale < 2)
		return (2);
	return (scale);
}
