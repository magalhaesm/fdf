/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:12:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/31 15:15:48 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	set_scale(t_scene *scene);
static int	get_scale(int row, int col);

void	init_scene(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_printf("No X server found.\n");
		exit(EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		WIN_WIDTH, WIN_HEIGHT, "Fil de Fer");
	data->scene.mid_width = WIN_WIDTH / 2;
	data->scene.mid_height = WIN_HEIGHT / 2;
	data->scene.default_scale = get_scale(data->scene.rows, data->scene.cols);
	data->scene.default_z = 0.1;
	data->scene.view = ISOMETRIC;
	reset_scene(&data->scene);
}

void	reset_scene(t_scene *scene)
{
	scene->scale = scene->default_scale;
	scene->z_scale = scene->default_z;
	set_scale(scene);
	scene->move_x = 0;
	scene->move_y = 0;
	scene->rotation.alpha = 0;
	scene->rotation.beta = 0;
	scene->rotation.gamma = 0;
}

int	zoom(int keysym, t_scene *scene)
{
	if (keysym == K_EQUAL)
		scene->scale += 1;
	else
		scene->scale -= 1;
	set_scale(scene);
	return (EXIT_SUCCESS);
}

static void	set_scale(t_scene *scene)
{
	scene->scaled_col = (scene->cols * scene->scale) / 2;
	scene->scaled_row = (scene->rows * scene->scale) / 2;
}

static int	get_scale(int row, int col)
{
	int	scale;
	int	area;

	area = WIN_WIDTH * WIN_HEIGHT / 4;
	scale = area / (row * col);
	scale = sqrt(scale);
	if (scale < 2)
		return (2);
	return (scale);
}
