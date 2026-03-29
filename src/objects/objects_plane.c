/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:58:27 by asando            #+#    #+#             */
/*   Updated: 2026/03/29 16:18:13 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

int	ft_hit_plane(t_ray ray, t_plane *pl, t_hit *hit)
{
	double	denom;
	double	t;

	denom = ft_vdot(pl->normal, ray.direction);
	if (fabs(denom) < 1e-06)
		return (0);
	t = ft_vdot(ft_vsub(pl->point, ray.origin), pl->normal) / denom;
	if (t < 1e-06)
		return (0);
	hit->t = t;
	hit->point = ft_ray_at(ray, t);
	hit->normal = pl->normal;
	hit->mat = pl->mat;
	return (1);
}
