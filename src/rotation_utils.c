/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:32:20 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/31 15:35:41 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_x(int keysym, t_scene *scene)
{
	if (keysym == K_W)
		scene->cache.alpha += 0.1;
	else
		scene->cache.alpha -= 0.1;
}

void	rotate_y(int keysym, t_scene *scene)
{
	if (keysym == K_A)
		scene->cache.beta -= 0.1;
	else
		scene->cache.beta += 0.1;
}

void	rotate_z(int keysym, t_scene *scene)
{
	if (keysym == K_Q)
		scene->cache.gamma -= 0.1;
	else
		scene->cache.gamma += 0.1;
}
