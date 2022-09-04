/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:43:39 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/09/04 16:44:59 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#define GRAY 0x22333b
#define BLUE 0x011627
#define FONT 0xadb5bd
#define TITLE 0xfdfffc
#define YELLOW 0xff9f1c

static void	put_controls(t_mlx *data);
static void	end_controls(t_mlx *data);
static void	show_legend(t_mlx *data);

int	redraw(t_mlx *data)
{
	if (data->menu)
		show_legend(data);
	draw_scene(data);
	return (EXIT_SUCCESS);
}

void	show_controls(t_mlx *data)
{
	if (data->menu == FALSE)
	{
		data->menu = TRUE;
		resize(data);
		show_legend(data);
	}
	else
	{
		data->menu = FALSE;
		resize(data);
	}
}

static void	show_legend(t_mlx *data)
{
	data->legend.ptr = mlx_new_image(data->mlx_ptr, CTRL_WIDTH, WIN_HEIGHT);
	data->legend.addr = mlx_get_data_addr(data->legend.ptr, \
		&data->legend.bpp, &data->legend.line_len, &data->legend.endian);
	render_background(&data->legend, BLUE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->legend.ptr, 0, 0);
	put_controls(data);
	end_controls(data);
	mlx_destroy_image(data->mlx_ptr, data->legend.ptr);
}

static void	put_controls(t_mlx *data)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 60, 40, TITLE, "CONTROLS");
	mlx_string_put(mlx, win, 30, 80, TITLE, "Moves");
	mlx_string_put(mlx, win, 50, 100, FONT, "Up: UP arrow");
	mlx_string_put(mlx, win, 50, 120, FONT, "Down: DOWN arrow");
	mlx_string_put(mlx, win, 50, 140, FONT, "Left: LEFT arrow");
	mlx_string_put(mlx, win, 50, 160, FONT, "Right: RIGHT arrow");
	mlx_string_put(mlx, win, 30, 200, TITLE, "Rotations");
	mlx_string_put(mlx, win, 50, 220, FONT, "X-axis: W / S");
	mlx_string_put(mlx, win, 50, 240, FONT, "Y-axis: A / D");
	mlx_string_put(mlx, win, 50, 260, FONT, "Z-axis: Q / E");
	mlx_string_put(mlx, win, 30, 300, TITLE, "Zoom");
	mlx_string_put(mlx, win, 50, 320, FONT, "Zoom in: +");
	mlx_string_put(mlx, win, 50, 340, FONT, "Zoom out: -");
	mlx_string_put(mlx, win, 30, 380, TITLE, "Altitude");
	mlx_string_put(mlx, win, 50, 400, FONT, "Increase: [");
	mlx_string_put(mlx, win, 50, 420, FONT, "Decrease: ]");
}

static void	end_controls(t_mlx *data)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 30, 460, TITLE, "Projections");
	mlx_string_put(mlx, win, 50, 480, FONT, "Isometric: I");
	mlx_string_put(mlx, win, 50, 500, FONT, "Orthografic: O");
	mlx_string_put(mlx, win, 30, 540, TITLE, "Reset: R");
	mlx_string_put(mlx, win, 50, 580, YELLOW, "author: mdias-ma");
	mlx_string_put(mlx, win, 50, 600, YELLOW, "Marcelo Magalhaes");
}
