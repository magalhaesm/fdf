/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:32:20 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/04/08 17:09:55 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	zoom(int keysym, t_scene *scene)
{
	if (keysym == K_EQUAL)
		scene->scale += 1;
	else
		scene->scale -= 1;
	if (scene->scale < 1)
		scene->scale = 1;
	set_scale(scene);
	return (TRUE);
}

int	translate(int keysym, t_scene *scene)
{
	if (keysym == K_UP)
		scene->move_y += 10;
	else if (keysym == K_DOWN)
		scene->move_y -= 10;
	else if (keysym == K_LEFT)
		scene->move_x += 10;
	else if (keysym == K_RIGHT)
		scene->move_x -= 10;
	return (TRUE);
}

int	rotate_x(int keysym, t_scene *scene)
{
	if (keysym == K_W)
		scene->cache.alpha -= 0.1;
	else
		scene->cache.alpha += 0.1;
	return (TRUE);
}

int	rotate_y(int keysym, t_scene *scene)
{
	if (keysym == K_A)
		scene->cache.beta += 0.1;
	else
		scene->cache.beta -= 0.1;
	return (TRUE);
}

int	rotate_z(int keysym, t_scene *scene)
{
	if (keysym == K_Q)
		scene->cache.gamma += 0.1;
	else
		scene->cache.gamma -= 0.1;
	return (TRUE);
}
