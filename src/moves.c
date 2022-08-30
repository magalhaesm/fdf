/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:32:20 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/30 14:41:42 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	move_view(int keysym, t_data *data)
{
	if (keysym == K_UP)
		data->scene.move_y += 10;
	else if (keysym == K_DOWN)
		data->scene.move_y -= 10;
	else if (keysym == K_LEFT)
		data->scene.move_x += 10;
	else if (keysym == K_RIGHT)
		data->scene.move_x -= 10;
}

void	rotate_x(int keysym, t_scene *scene)
{
	if (keysym == K_W)
		scene->rotation.alpha += 0.1;
	else
		scene->rotation.alpha -= 0.1;
}

void	rotate_y(int keysym, t_scene *scene)
{
	if (keysym == K_A)
		scene->rotation.beta -= 0.1;
	else
		scene->rotation.beta += 0.1;
}

void	rotate_z(int keysym, t_scene *scene)
{
	if (keysym == K_Q)
		scene->rotation.gamma -= 0.1;
	else
		scene->rotation.gamma += 0.1;
}
