/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:05:33 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/22 16:15:09 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	iabs(int x);
static void	set_variables(t_line *line, t_point p1, t_point p2);

void	draw_line(t_img *canvas, t_point p1, t_point p2, int color)
{
	t_line	line;

	set_variables(&line, p1, p2);
	while (line.i <= (line.dx + line.dy))
	{
		put_pixel(canvas, p1.x, p1.y, color);
		line.e1 = line.error + line.dy;
		line.e2 = line.error - line.dx;
		if (iabs(line.e1) < iabs(line.e2))
		{
			p1.x += line.ix;
			line.error = line.e1;
		}
		else
		{
			p1.y += line.iy;
			line.error = line.e2;
		}
		line.i++;
	}
}

static void	set_variables(t_line *line, t_point p1, t_point p2)
{
	line->dx = iabs(p2.x - p1.x);
	line->dy = iabs(p2.y - p1.y);
	if (p1.x < p2.x)
		line->ix = 1;
	else
		line->ix = -1;
	if (p1.y < p2.y)
		line->iy = 1;
	else
		line->iy = -1;
	line->error = 0;
	line->i = 0;
}

static int	iabs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
