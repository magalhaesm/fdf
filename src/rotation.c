/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:35:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/04/08 17:09:30 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	set_alpha(t_point *p, const t_cache *cache);
static void	set_beta(t_point *p, const t_cache *cache);
static void	set_gamma(t_point *p, const t_cache *cache);

void	rotate(t_point *p, const t_cache *cache)
{
	set_alpha(p, cache);
	set_beta(p, cache);
	set_gamma(p, cache);
}

// Cache angles
void	set_rotation(t_cache *cache)
{
	cache->cos_alpha = cos(cache->alpha);
	cache->sin_alpha = sin(cache->alpha);
	cache->cos_beta = cos(cache->beta);
	cache->sin_beta = sin(cache->beta);
	cache->cos_gamma = cos(cache->gamma);
	cache->sin_gamma = sin(cache->gamma);
}

static void	set_alpha(t_point *p, const t_cache *cache)
{
	int	temp_y;

	temp_y = p->y;
	p->y = temp_y * cache->cos_alpha + p->z * cache->sin_alpha;
	p->z = temp_y * -cache->sin_alpha + p->z * cache->cos_alpha;
}

static void	set_beta(t_point *p, const t_cache *cache)
{
	int	temp_x;

	temp_x = p->x;
	p->x = temp_x * cache->cos_beta + p->z * -cache->sin_beta;
	p->z = temp_x * cache->sin_beta + p->z * cache->cos_beta;
}

static void	set_gamma(t_point *p, const t_cache *cache)
{
	int	temp_x;

	temp_x = p->x;
	p->x = temp_x * cache->cos_gamma + p->y * cache->sin_gamma;
	p->y = temp_x * -cache->sin_gamma + p->y * cache->cos_gamma;
}
