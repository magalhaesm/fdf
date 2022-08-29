/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:12:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/28 22:53:46 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	set_scale(t_data *data);
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
	reset_scene(data);
}

void	reset_scene(t_data *data)
{
	data->scene.scale = data->scene.default_scale;
	data->scene.z_scale = data->scene.default_z;
	set_scale(data);
	data->scene.move_x = 0;
	data->scene.move_y = 0;
}

int	zoom(int keysym, t_data *data)
{
	if (keysym == K_equal)
		data->scene.scale += 1;
	else
		data->scene.scale -= 1;
	set_scale(data);
	return (EXIT_SUCCESS);
}

static void	set_scale(t_data *data)
{
	data->scene.scaled_col = (data->scene.cols * data->scene.scale) / 2;
	data->scene.scaled_row = (data->scene.rows * data->scene.scale) / 2;
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
