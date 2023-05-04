/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:09:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/04/09 15:37:16 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#define SIN_30 0.500000
#define COS_30 0.866025

static void	isometric(t_point *p);
static void	render_scene(const t_mlx *data);
static void	set_point(t_point *p, int row, int col, const t_scene *scene);

void	draw_scene(t_mlx *data)
{
	data->canvas.ptr = mlx_new_image(
			data->mlx_ptr, data->canvas.width, WIN_HEIGHT);
	data->canvas.addr = mlx_get_data_addr(
			data->canvas.ptr, &data->canvas.bpp,
			&data->canvas.line_len, &data->canvas.endian);
	set_rotation(&data->scene.cache);
	render_scene(data);
	mlx_put_image_to_window(
		data->mlx_ptr, data->win_ptr,
		data->canvas.ptr, data->canvas.x, 0);
	mlx_destroy_image(data->mlx_ptr, data->canvas.ptr);
}

void	init_scene(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_putendl_fd("Error: No X server found.", STDERR_FILENO);
		destroy_map(&data->scene);
		exit(EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "Fil de Fer");
	data->show_legend = FALSE;
	data->legend.width = CTRL_WIDTH;
	data->legend.height = WIN_HEIGHT;
	data->canvas.height = WIN_HEIGHT;
	data->scene.std_z = 0.1;
	data->scene.view = ISOMETRIC;
	resize(data);
	reset_scene(&data->scene);
}

static void	isometric(t_point *p)
{
	int	temp_x;

	temp_x = p->x;
	p->x = (temp_x - p->y) * COS_30;
	p->y = (temp_x + p->y) * SIN_30 - p->z;
}

static void	render_scene(const t_mlx *data)
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
			set_point(&p1, row, col, &data->scene);
			if (col + 1 < data->scene.cols)
			{
				set_point(&p2, row, col + 1, &data->scene);
				draw_line(&data->canvas, p1, p2);
			}
			if (row + 1 < data->scene.rows)
			{
				set_point(&p2, row + 1, col, &data->scene);
				draw_line(&data->canvas, p1, p2);
			}
		}
	}
}

/* Apply transformations to the point */
static void	set_point(t_point *p, int row, int col, const t_scene *scene)
{
	p->x = col * scene->scale - scene->scaled_col;
	p->y = row * scene->scale - scene->scaled_row;
	p->z = scene->map[row][col].z * scene->scale * scene->z_scale;
	p->color = scene->map[row][col].color;
	rotate(p, &scene->cache);
	if (scene->view == ISOMETRIC)
		isometric(p);
	p->x += scene->mid_width + scene->move_x;
	p->y += scene->mid_height + scene->move_y;
}
