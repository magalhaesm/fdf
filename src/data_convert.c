/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:34:25 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/09/05 08:36:56 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	to_color(char *str);
static void	extract(t_alt *altitude, char *data);

void	data_convert(t_scene *scene, int fd)
{
	int		row;
	int		col;
	char	*line;
	char	*trim;
	char	**buffer;

	row = 0;
	while (row < scene->rows)
	{
		col = 0;
		line = get_next_line(fd);
		trim = ft_strtrim(line, "\n");
		buffer = ft_split(trim, ' ');
		while (col < scene->cols)
		{
			extract(&scene->map[row][col], buffer[col]);
			free(buffer[col]);
			col++;
		}
		free(buffer);
		free(trim);
		free(line);
		row++;
	}
	free(get_next_line(fd));
}

void	generate_map(t_scene *scene)
{
	int	row;

	row = 0;
	scene->map = ft_calloc(sizeof(t_alt *), scene->rows);
	while (row < scene->rows)
	{
		scene->map[row] = ft_calloc(sizeof(t_alt), scene->cols);
		row++;
	}
}

void	destroy_map(t_scene *scene)
{
	int	row;

	row = 0;
	while (row < scene->rows)
		free(scene->map[row++]);
	free(scene->map);
}

static void	extract(t_alt *altitude, char *data)
{
	char	*hex;

	hex = ft_strchr(data, ',');
	altitude->z = ft_atoi(data);
	if (hex)
		altitude->color = to_color(hex);
	else
	{
		if (altitude->z)
			altitude->color = STD_Z;
		else
			altitude->color = GRID;
	}
}

static int	to_color(char *str)
{
	int	sum;
	int	symbol;
	int	pos_value;
	int	index;

	pos_value = 1;
	symbol = 0;
	sum = 0;
	index = ft_strlen(str) - 1;
	while (str[index] != 'x' && index)
	{
		symbol = str[index];
		if (symbol >= 'a' && symbol <= 'f')
			symbol -= 87;
		else
			symbol -= 48;
		sum += symbol * pos_value;
		pos_value *= 16;
		index--;
	}
	return (sum);
}
