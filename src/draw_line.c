/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:05:33 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/04/07 15:56:09 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#define RED 0
#define GREEN 1
#define BLUE 2

static int	iabs(int number);
static void	setup(t_line *line, t_point p1, t_point p2);
static void	set_color_channels(t_point *p1, t_point *p2);
static int	get_color(t_point *p1, t_point *p2, const t_line *line);

void	draw_line(const t_img *canvas, t_point p1, t_point p2)
{
	t_line	line;

	setup(&line, p1, p2);
	set_color_channels(&p1, &p2);
	while (line.pos <= line.len)
	{
		put_pixel(canvas, p1.x, p1.y, get_color(&p1, &p2, &line));
		line.e1 = line.err + line.dy;
		line.e2 = line.err - line.dx;
		if (iabs(line.e1) < iabs(line.e2))
		{
			p1.x += line.ix;
			line.err = line.e1;
		}
		else
		{
			p1.y += line.iy;
			line.err = line.e2;
		}
		line.pos++;
	}
}

static void	setup(t_line *line, t_point p1, t_point p2)
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
	line->err = 0;
	line->len = line->dx + line->dy;
	line->pos = 0;
}

static void	set_color_channels(t_point *p1, t_point *p2)
{
	p1->rgb[RED] = (p1->color >> 16) & 0xFF;
	p1->rgb[GREEN] = (p1->color >> 8) & 0xFF;
	p1->rgb[BLUE] = p1->color & 0xFF;
	p2->rgb[RED] = (p2->color >> 16) & 0xFF;
	p2->rgb[GREEN] = (p2->color >> 8) & 0xFF;
	p2->rgb[BLUE] = p2->color & 0xFF;
}

static int	get_color(t_point *p1, t_point *p2, const t_line *line)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	percentage = (double)line->pos / line->len;
	red = (1 - percentage) * p1->rgb[RED];
	red += percentage * p2->rgb[RED];
	green = (1 - percentage) * p1->rgb[GREEN];
	green += percentage * p2->rgb[GREEN];
	blue = (1 - percentage) * p1->rgb[BLUE];
	blue += percentage * p2->rgb[BLUE];
	return (red << 16 | green << 8 | blue);
}

static int	iabs(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}
