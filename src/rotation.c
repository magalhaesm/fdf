/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:35:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/31 15:34:25 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void set_alpha(t_point *p, t_cache r);
static void set_beta(t_point *p, t_cache r);
static void set_gamma(t_point *p, t_cache r);

void	rotate(t_point *p, t_cache cache)
{
	set_alpha(p, cache);
	set_beta(p, cache);
	set_gamma(p, cache);
}

void	set_rotation(t_cache *cache)
{
	cache->cos_alpha = cos(cache->alpha);
	cache->sin_alpha = sin(cache->alpha);
	cache->cos_beta = cos(cache->beta);
	cache->sin_beta = sin(cache->beta);
	cache->cos_gamma = cos(cache->gamma);
	cache->sin_gamma = sin(cache->gamma);
}

static void set_alpha(t_point *p, t_cache r)
{
	int	temp_y;

	temp_y = p->y;
	p->y = temp_y * r.cos_alpha - p->z * r.sin_alpha;
	p->z = temp_y * r.sin_alpha + p->z * r.cos_alpha;
}

static void set_beta(t_point *p, t_cache r)
{
	int	temp_x;

	temp_x = p->x;
	p->x = temp_x * r.cos_beta + p->z * r.sin_beta;
	p->z = -temp_x * r.sin_beta + p->z * r.cos_beta;
}

static void set_gamma(t_point *p, t_cache r)
{
	int	temp_x;

	temp_x = p->x;
	p->x = temp_x * r.cos_gamma - p->y * r.sin_gamma;
	p->y = temp_x * r.sin_gamma + p->y * r.cos_gamma;
}
