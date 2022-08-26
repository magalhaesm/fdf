/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:48:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/26 19:05:13 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#define INVALID_MAP -1

static int	point_counter(const char *line);
static void	record(int *last, int *points);
static void	set_map_dimensions(t_scene *scene, int fd);

void	load_map(t_scene *scene, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	set_map_dimensions(scene, fd);
	close(fd);
	generate_map(scene);
	fd = open(file, O_RDONLY);
	data_convert(scene, fd);
	close(fd);
}

static void	record(int *last, int *points)
{
	if (*last > 0 && *last != *points)
	{
		*last = -1;
		*points = -1;
	}
	*last = *points;
}

static int	point_counter(const char *line)
{
	static int	last;
	int			index;
	int			points;
	t_bool		is_point;

	index = 0;
	points = 0;
	is_point = FALSE;
	if (last == INVALID_MAP)
		return (last);
	while (line[index] && line[index] != '\n')
	{
		if (line[index] != ' ' && is_point == FALSE)
		{
			is_point = TRUE;
			points++;
		}
		else if (line[index] == ' ')
			is_point = FALSE;
		index++;
	}
	record(&last, &points);
	return (points);
}

static void	set_map_dimensions(t_scene *scene, int fd)
{
	char	*line;

	line = "";
	scene->cols = 0;
	scene->rows = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			scene->cols = point_counter(line);
			scene->rows++;
			free(line);
		}
	}
	if (scene->cols == -1 || scene->rows == 0)
		exit(EXIT_FAILURE);
}
