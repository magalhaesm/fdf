/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:44:56 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/31 15:11:55 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	translate(int keysym, t_scene *scene)
{
	if (keysym == K_UP)
		scene->move_y += 10;
	else if (keysym == K_DOWN)
		scene->move_y -= 10;
	else if (keysym == K_LEFT)
		scene->move_x += 10;
	else if (keysym == K_RIGHT)
		scene->move_x -= 10;
}
