/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:04:25 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/25 07:40:01 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_map(t_scene *scene)
{
	int	row;

	row = 0;
	while (row <= scene->rows)
		free(scene->map[row++]);
	free(scene->map);
}
