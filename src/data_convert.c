/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:34:25 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/25 11:49:02 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	generate_map(t_scene *scene)
{
	int	row;

	row = 0;
	scene->map = malloc(sizeof(t_alt *) * scene->rows);
	while (row < scene->rows)
	{
		scene->map[row] = ft_calloc(sizeof(t_alt), scene->cols);
		row++;
	}
}

void	data_convert(t_scene *scene, int fd)
{
	int		row;
	int		col;
	char	*line;
	char	**buffer;

	row = 0;
	while (row < scene->rows)
	{
		col = 0;
		line = get_next_line(fd);
		buffer = ft_split(line, ' ');
		free(line);
		while (col < scene->cols)
		{
			scene->map[row][col].z = ft_atoi(buffer[col]);
			free(buffer[col]);
			col++;
		}
		row++;
		free(buffer[col]);
		free(buffer);
	}
	free(get_next_line(fd));
}
