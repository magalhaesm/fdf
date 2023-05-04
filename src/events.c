/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:18:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/04/09 15:15:11 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	keypress_handler(int keysym, t_mlx *data);
static int	change_perspective(int keysym, t_scene *scene);
static int	change_altitude(int keysym, t_scene *scene);
static int	scene_motion(int keysym, t_scene *scene);

void	event_handler(t_mlx *data)
{
	mlx_expose_hook(data->win_ptr, redraw, data);
	mlx_hook(data->win_ptr, DESTROYNOTIFY, NOEVENTMASK, quit, data);
	mlx_hook(data->win_ptr, KEYPRESS, KEYPRESSMASK, keypress_handler, data);
}

static int	keypress_handler(int keysym, t_mlx *data)
{
	t_bool	motion;

	motion = scene_motion(keysym, &data->scene);
	if (motion)
		draw_scene(data);
	else if (keysym == K_SLASH)
		show_controls(data);
	else if (keysym == K_ESCAPE)
		quit(data);
	return (EXIT_SUCCESS);
}

static int	scene_motion(int keysym, t_scene *scene)
{
	if (keysym >= K_LEFT && keysym <= K_DOWN)
		return (translate(keysym, scene));
	if (keysym == K_W || keysym == K_S)
		return (rotate_x(keysym, scene));
	if (keysym == K_A || keysym == K_D)
		return (rotate_y(keysym, scene));
	if (keysym == K_Q || keysym == K_E)
		return (rotate_z(keysym, scene));
	if (keysym == K_EQUAL || keysym == K_MINUS)
		return (zoom(keysym, scene));
	if (keysym == K_BRACKETLEFT || keysym == K_BRACKETRIGHT)
		return (change_altitude(keysym, scene));
	if (keysym == K_I || keysym == K_O)
		return (change_perspective(keysym, scene));
	if (keysym == K_R)
		return (reset_scene(scene));
	return (FALSE);
}

static int	change_altitude(int keysym, t_scene *scene)
{
	if (keysym == K_BRACKETLEFT)
		scene->z_scale += 0.1;
	else
		scene->z_scale -= 0.1;
	return (TRUE);
}

static int	change_perspective(int keysym, t_scene *scene)
{
	if (keysym == K_I)
		scene->view = ISOMETRIC;
	else
		scene->view = ORTHOGRAPHIC;
	return (TRUE);
}
