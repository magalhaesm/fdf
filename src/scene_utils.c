/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:12:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/09/04 20:38:08 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	get_scale(t_mlx *data);
static void	set_scale(t_scene *scene);

void	resize(t_mlx *data)
{
	if (data->menu)
	{
		data->canvas.width -= data->legend.width;
		data->canvas.x = data->legend.width;
	}
	else
	{
		data->canvas.width = WIN_WIDTH;
		data->canvas.x = 0;
	}
	data->scene.mid_width = data->canvas.width / 2;
	data->scene.mid_height = WIN_HEIGHT / 2;
	data->scene.std_scale = get_scale(data);
}

void	reset_scene(t_scene *scene)
{
	scene->scale = scene->std_scale;
	scene->z_scale = scene->std_z;
	set_scale(scene);
	scene->move_x = 0;
	scene->move_y = 0;
	scene->cache.alpha = 0;
	scene->cache.beta = 0;
	scene->cache.gamma = 0;
}

void	zoom(int keysym, t_scene *scene)
{
	if (keysym == K_EQUAL)
		scene->scale += 1;
	else
		scene->scale -= 1;
	if (scene->scale < 2)
		scene->scale = 2;
	set_scale(scene);
}

static void	set_scale(t_scene *scene)
{
	scene->scaled_col = (scene->cols * scene->scale) / 2;
	scene->scaled_row = (scene->rows * scene->scale) / 2;
}

static int	get_scale(t_mlx *data)
{
	int	scale;
	int	area;

	area = data->canvas.width * WIN_HEIGHT / 4;
	scale = area / (data->scene.rows * data->scene.cols);
	scale = sqrt(scale);
	if (scale < 2)
		return (2);
	return (scale);
}
