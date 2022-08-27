/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:18:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/27 13:00:12 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	quit(t_data *data);
static int	key_release(int keysym, t_data *data);
int	zoom(int keysym, t_data *data);

void	event_handler(t_data *data)
{
	mlx_hook(data->win_ptr, EnterNotify, EnterWindowMask, draw_scene, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, quit, data);
	mlx_key_hook(data->win_ptr, key_release, data);
}

int	zoom(int keysym, t_data *data)
{
	if (keysym == XK_Up)
		data->scene.scale += 2;
	else
		data->scene.scale -= 2;
	data->scene.scaled_col = (data->scene.cols * data->scene.scale) / 2;
	data->scene.scaled_row = (data->scene.rows * data->scene.scale) / 2;
	draw_scene(data);
	return (EXIT_SUCCESS);
}

static int	key_release(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		quit(data);
	if (keysym == XK_Up || keysym == XK_Down)
		zoom(keysym, data);
	return (EXIT_SUCCESS);
}

static int	quit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_map(&data->scene);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}
