/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:18:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/09/03 16:21:19 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	quit(t_mlx *data);
static int	key_press(int keysym, t_mlx *data);
static int	key_release(int keysym, t_mlx *data);
static int	change_altitude(int keysym, t_scene *scene);

void	event_handler(t_mlx *data)
{
	mlx_expose_hook(data->win_ptr, draw_scene, data);
	mlx_hook(data->win_ptr, DESTROYNOTIFY, NOEVENTMASK, quit, data);
	mlx_hook(data->win_ptr, KEYPRESS, KEYPRESSMASK, key_press, data);
	mlx_key_hook(data->win_ptr, key_release, data);
}

static int	change_altitude(int keysym, t_scene *scene)
{
	if (keysym == K_BRACKETLEFT)
		scene->z_scale += 0.1;
	else
		scene->z_scale -= 0.1;
	return (EXIT_SUCCESS);
}

static int	key_release(int keysym, t_mlx *data)
{
	if (keysym == K_R)
		reset_scene(&data->scene);
	else if (keysym == K_I)
		data->scene.view = ISOMETRIC;
	else if (keysym == K_O)
		data->scene.view = ORTHOGRAPHIC;
	else if (keysym == K_ESCAPE)
		quit(data);
	draw_scene(data);
	return (EXIT_SUCCESS);
}

static int	key_press(int keysym, t_mlx *data)
{
	if (keysym >= K_LEFT && keysym <= K_DOWN)
		translate(keysym, &data->scene);
	else if (keysym == K_W || keysym == K_S)
		rotate_x(keysym, &data->scene);
	else if (keysym == K_A || keysym == K_D)
		rotate_y(keysym, &data->scene);
	else if (keysym == K_Q || keysym == K_E)
		rotate_z(keysym, &data->scene);
	else if (keysym == K_EQUAL || keysym == K_MINUS)
		zoom(keysym, &data->scene);
	else if (keysym == K_BRACKETLEFT || keysym == K_BRACKETRIGHT)
		change_altitude(keysym, &data->scene);
	draw_scene(data);
	return (EXIT_SUCCESS);
}

static int	quit(t_mlx *data)
{
	int	row;

	row = 0;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	while (row < data->scene.rows)
		free(data->scene.map[row++]);
	free(data->scene.map);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}
