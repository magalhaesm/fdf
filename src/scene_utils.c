/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:12:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/28 11:33:16 by mdias-ma         ###   ########.fr       */
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
		WINDOW_WIDTH, WINDOW_HEIGHT, "Fil de Fer");
	data->scene.mid_width = WINDOW_WIDTH / 2;
	data->scene.mid_height = WINDOW_HEIGHT / 2;
	data->scene.default_scale = get_scale(data->scene.rows, data->scene.cols);
	data->scene.scale = data->scene.default_scale;
	set_scale(data);
}

void	reset_scene(t_data *data)
{
	data->scene.scale = data->scene.default_scale;
	set_scale(data);
}

int	zoom(int keysym, t_data *data)
{
	if (keysym == XK_equal)
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

	area = WINDOW_WIDTH * WINDOW_HEIGHT / 4;
	scale = area / (row * col);
	scale = sqrt(scale);
	if (scale < 2)
		return (2);
	return (scale);
}
