/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:18:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/28 11:53:57 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <mlx.h>

static int	quit(t_data *data);
static int	key_press(int keysym, t_data *data);
static int	key_release(int keysym, t_data *data);

void	event_handler(t_data *data)
{
	mlx_expose_hook(data->win_ptr, draw_scene, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, quit, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_press, data);
	mlx_key_hook(data->win_ptr, key_release, data);
}

static int	key_release(int keysym, t_data *data)
{
	if (keysym == XK_r)
		reset_scene(data);
	else if (keysym == XK_p)
		data->scene.view = PARALLEL;
	else if (keysym == XK_i)
		data->scene.view = ISOMETRIC;
	draw_scene(data);
	return (EXIT_SUCCESS);
}

static int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		quit(data);
	else if (keysym == XK_equal || keysym == XK_minus)
		zoom(keysym, data);
	draw_scene(data);
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
