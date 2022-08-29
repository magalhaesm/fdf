/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:32:20 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/28 22:58:37 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	move_view(int keysym, t_data *data)
{
	if (keysym == K_Up)
		data->scene.move_y += 10;
	else if (keysym == K_Down)
		data->scene.move_y -= 10;
	else if (keysym == K_Left)
		data->scene.move_x += 10;
	else if (keysym == K_Right)
		data->scene.move_x -= 10;
}
