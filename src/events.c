/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:18:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/27 00:38:01 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	quit(t_data *data);
static int	key_release(int keysym, t_data *data);

void	register_events(t_data *data)
{
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, quit, data);
	mlx_key_hook(data->win_ptr, key_release, data);
}

static int	key_release(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		quit(data);
	return (EXIT_SUCCESS);
}

static int	quit(t_data *data)
{
	(void) data;
	exit(EXIT_SUCCESS);
}
