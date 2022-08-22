/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:05:45 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/22 12:13:59 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

#include "../include/fdf.h"

#define MLX_ERROR 1

// ETAPAS:
// obter o número de linhas e colunas
// -> o mapa estará apropriadamente formatado quando,
// para cada linha, houver o mesmo número de pontos.
// alocar um vetor do tamanho do número de linhas
// para cada linha, um vetor com o número de colunas

// - usa uma matriz de cores
// pq?
// como?
// get_matrix_color: obtém as cores dos pontos uma linha por vez

// a função de plotagem precisa definir o comprimento das linhas (tile size)
// cada ponto tem 2 linhas; para direita e para baixo

void	put_pixel(t_img *canvas, int x, int y, int color);

int	iabs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	set_variables(t_line *line, t_point p1, t_point p2)
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

void	draw_line(t_img *canvas, t_point p1, t_point p2, int color)
{
	t_line line;

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

int	encode_rgb(t_byte red, t_byte green, t_byte blue)
{
	return (red << 16 | green << 8 | blue);
}

void	put_pixel(t_img *canvas, int x, int y, int color)
{
	char	*pixel;
	if (x < WINDOW_WIDTH && x >= 0 && y <= WINDOW_HEIGHT && y >= 0)
	{
		pixel = canvas->addr + (y * canvas->line_len + x *
			(canvas->bits_per_pixel / 8));
		*(int *)pixel = color;
	}
}

void	render_background(t_img *canvas, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			put_pixel(canvas, x++, y, color);
		y++;
	}
}

int	quit(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->canvas.img_ptr);
		mlx_loop_end(data->mlx_ptr);
	}
	ft_printf("Pressionada tecla: %d\n", keysym);
	return (0);
}

// void	draw(t_data *data)
// {
// 	int		col;
// 	int		row;
// 	t_point	p1;
// 	t_point	p2;
//
// 	row = 0;
// 	while (row < data->scene.rows)
// 	{
// 		col = 0;
// 		while (col < data->scene.cols)
// 		{
// 			if (col + 1 <= data->scene.cols)
// 			{
// 				p1.x = col * data.scene.scale;
// 				y = row * data.scene.scale;
// 				y -= (data.scene.rows * data.scene.scale) / 2;
// 				x -= (data.scene.cols * data.scene.scale) / 2;
// 				x += WINDOW_WIDTH / 2;
// 				y += WINDOW_HEGHT / 2;
// 				draw_line(&data->canvas, p1, p2, encode_rgb(0, 255, 255));
// 			}
// 			if (row + 1 <= data->scene.rows)
// 			{
// 				p1.x = data->scene.scale * col;
// 				p1.y = data->scene.scale * (row + 1);
// 				p1.x -= data->scene.cols / 2;
// 				p1.y -= data->scene.rows / 2;
// 				p1.x += WINDOW_WIDTH / 2;
// 				p1.y += WINDOW_HEGHT / 2;
// 				draw_line(&data->canvas, p1, p2, encode_rgb(0, 255, 255));
// 			}
// 			// ft_printf("%d ", data.scene.map[row][col++]);
// 			col++;
// 		}
// 		// ft_printf("\n");
// 		row++;
// 	}
// }

void	draw(t_data *data)
{
	t_point	p1;
	t_point	p2;

	p1.x = 256;
	p1.y = 152;
	p2.x = 283;
	p2.y = 152;
	draw_line(&data->canvas, p1, p2, encode_rgb(0, 255, 255));

	p1.x = 256;
	p1.y = 152;
	p2.x = 256;
	p2.y = 179;
	draw_line(&data->canvas, p1, p2, encode_rgb(0, 255, 255));
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	render_background(&data->canvas, CANVAS_BG);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->canvas.img_ptr, 0, 0);
	return (0);
}

void	create_scene(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
		WINDOW_WIDTH, WINDOW_HEIGHT, "Fil de Fer");
	data->canvas.img_ptr = mlx_new_image(data->mlx_ptr,
		WINDOW_WIDTH, WINDOW_HEIGHT);
	data->canvas.addr = mlx_get_data_addr(data->canvas.img_ptr,
		&data->canvas.bits_per_pixel,
		&data->canvas.line_len, &data->canvas.endian);
	// render_background(&data->canvas,  0xffff00);
}

int	get_scale(int row, int col)
{
	int	scale;
	int	area;

	area = WINDOW_WIDTH * WINDOW_HEIGHT / 4;
	scale = area / (row * col);
	scale = sqrt(scale);
	if (scale < 2)
		return (2);
	return (scale);
}

int	main(int argc, char **argv)
{
	int		col;
	int		row;
	int		x;
	int		y;
	t_data	data;

	(void) argc;
	load_data(&data.scene, argv[1]);
	data.scene.scale = get_scale(data.scene.rows, data.scene.cols);
	data.cache.scaled_col = (data.scene.cols * data.scene.scale) / 2;
	data.cache.scaled_row = (data.scene.rows * data.scene.scale) / 2;
	data.cache.mid_width = WINDOW_WIDTH / 2;
	data.cache.mid_height = WINDOW_HEIGHT / 2;

	create_scene(&data);
	// set_default
	row = 0;
	while (row <= 5)
	// while (row <= data.scene.rows)
	{
		col = 0;
		while (col <= 5)
		// while (col <= data.scene.cols)
		{
			// NOTA: há valores que devem estar em cache
			x = col * data.scene.scale;
			y = row * data.scene.scale;
			x -= data.cache.scaled_col;
			y -= data.cache.scaled_row;
			x += data.cache.mid_width;
			y += data.cache.mid_height;
			ft_printf("(%d, %d) ", x, y);
			// ft_printf("%d ", data.scene.map[row][col++]);
			col++;
		}
		ft_printf("\n");
		row++;
	}

	render(&data);
	// NOTA: renderiza continuamente (ineficiente)
	// mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, quit, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free_map(&data.scene);
	free(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
