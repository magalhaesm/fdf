/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:43:39 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/09/04 14:12:26 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#define GRAY 0x22333b
#define BLUE 0x011627
#define FONT 0xf2f4f3

static void	put_controls(t_mlx *data);
static void	show_legend(t_mlx *data);

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

static void show_legend(t_mlx *data)
{
	data->legend.ptr = mlx_new_image(data->mlx_ptr, CTRL_WIDTH, WIN_HEIGHT);
	data->legend.addr = mlx_get_data_addr(data->legend.ptr, \
		&data->legend.bpp, &data->legend.line_len, &data->legend.endian);
	render_background(&data->legend, BLUE);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->legend.ptr, 0, 0);
	put_controls(data);
	mlx_destroy_image(data->mlx_ptr, data->legend.ptr);
}

static void	put_controls(t_mlx *data)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 90, 20, FONT, "FdF");
	mlx_string_put(mlx, win, 20, 40, FONT, "author: mdias-ma");
	mlx_string_put(mlx, win, 90, 80, FONT, "MENU");
	mlx_string_put(mlx, win, 20, 100, FONT, "Moves");
	mlx_string_put(mlx, win, 40, 115, FONT, "Up: UP Key");
	mlx_string_put(mlx, win, 40, 130, FONT, "Down: DOWN key");
	mlx_string_put(mlx, win, 40, 145, FONT, "Left: LEFT key");
	mlx_string_put(mlx, win, 40, 160, FONT, "Right: RIGHT key");
	mlx_string_put(mlx, win, 20, 185, FONT, "Rotations");
	mlx_string_put(mlx, win, 40, 200, FONT, "X-axis = 'W' and 'S'");
	mlx_string_put(mlx, win, 40, 215, FONT, "Y-axis = 'A' and 'D'");
	mlx_string_put(mlx, win, 40, 230, FONT, "Z-axis = 'Q' and 'E'");
	mlx_string_put(mlx, win, 20, 255, FONT, "Zoom");
	mlx_string_put(mlx, win, 40, 270, FONT, "Zoom in: '+'");
	mlx_string_put(mlx, win, 40, 285, FONT, "Zoom out: '-'");
	mlx_string_put(mlx, win, 20, 310, FONT, "Z-axis");
	mlx_string_put(mlx, win, 40, 325, FONT, "Increase: '['");
	mlx_string_put(mlx, win, 40, 340, FONT, "Decrease: ']'");
}
