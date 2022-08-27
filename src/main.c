/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:05:45 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/27 06:31:14 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void) argc;
	load_map(&data.scene, argv[1]);
	data.scene.scale = get_scale(data.scene.rows, data.scene.cols);
	data.scene.scaled_col = (data.scene.cols * data.scene.scale) / 2;
	data.scene.scaled_row = (data.scene.rows * data.scene.scale) / 2;
	data.scene.mid_width = WINDOW_WIDTH / 2;
	data.scene.mid_height = WINDOW_HEIGHT / 2;
	scene_init(&data);
	render_scene(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.canvas.ptr, 0, 0);
	register_events(&data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
