/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:34:25 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/30 19:19:13 by mdias-ma         ###   ########.fr       */
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
			extract(&scene->map[row][col], buffer[col]);
			free(buffer[col]);
			col++;
		}
		row++;
		free(buffer[col]);
		free(buffer);
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

static void	extract(t_alt *altitude, char *data)
{
	char	*hex;

	hex = ft_strchr(data, ',');
	if (hex)
	{
		altitude->z = ft_atoi(data);
		altitude->color = to_color(hex);
	}
	else
	{
		altitude->z = ft_atoi(data);
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
		if (symbol >= 'A' && symbol <= 'F')
			symbol -= 55;
		else
			symbol -= 48;
		sum += symbol * pos_value;
		pos_value *= 16;
		index--;
	}
	return (sum);
}
