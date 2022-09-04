/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:02:38 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/09/04 10:50:57 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel(const t_img *image, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= image->width || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(int *)pixel = color;
}

void	render_background(t_img *image, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < image->width)
			put_pixel(image, x++, y, color);
		y++;
	}
}
