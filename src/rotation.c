/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:35:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/31 14:51:04 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void set_alpha(t_point *p, t_rot r);
static void set_beta(t_point *p, t_rot r);
static void set_gamma(t_point *p, t_rot r);

void	rotate(t_point *p, t_rot rotation)
{
	set_alpha(p, rotation);
	set_beta(p, rotation);
	set_gamma(p, rotation);
}

void	set_rotation(t_scene *scene)
{
	scene->rotation.cos_alpha = cos(scene->rotation.alpha);
	scene->rotation.sin_alpha = sin(scene->rotation.alpha);
	scene->rotation.cos_beta = cos(scene->rotation.beta);
	scene->rotation.sin_beta = sin(scene->rotation.beta);
	scene->rotation.cos_gamma = cos(scene->rotation.gamma);
	scene->rotation.sin_gamma = sin(scene->rotation.gamma);
}

static void set_alpha(t_point *p, t_rot r)
{
	int	temp_y;

	temp_y = p->y;
	p->y = temp_y * r.cos_alpha - p->z * r.sin_alpha;
	p->z = temp_y * r.sin_alpha + p->z * r.cos_alpha;
}

static void set_beta(t_point *p, t_rot r)
{
	int	temp_x;

	temp_x = p->x;
	p->x = temp_x * r.cos_beta + p->z * r.sin_beta;
	p->z = -temp_x * r.sin_beta + p->z * r.cos_beta;
}

static void set_gamma(t_point *p, t_rot r)
{
	int	temp_x;

	temp_x = p->x;
	p->x = temp_x * r.cos_gamma - p->y * r.sin_gamma;
	p->y = temp_x * r.sin_gamma + p->y * r.cos_gamma;
}
