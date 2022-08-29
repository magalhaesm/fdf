/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:34:25 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/29 07:28:51 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_htoi(char *str);
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
		altitude->color = ft_htoi(hex);
	}
	else
	{
		altitude->z = ft_atoi(data);
		if (altitude->z)
			altitude->color = 0x990000;
		else
			altitude->color = GRID;
	}
}

static int	ft_htoi(char *str)
{
	int	index;
	int	nbr;
	int	i;
	int	n;

	i = 1;
	n = 0;
	nbr = 0;
	index = ft_strlen(str) - 1;
	while (str[index] != 'x')
	{
		n = str[index];
		if (n >= 'A' && n <= 'F')
			n -= 55;
		else
			n -= 48;
		nbr += n * i;
		index--;
		i *= 16;
	}
	return (nbr);
}
