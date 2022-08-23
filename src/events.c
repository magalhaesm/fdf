/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:18:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/23 18:18:20 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	quit(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->canvas.img_ptr);
		mlx_loop_end(data->mlx_ptr);
	}
	return (0);
}
