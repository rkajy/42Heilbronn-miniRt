/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_cylinder_caps.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:59:48 by asando            #+#    #+#             */
/*   Updated: 2026/08/16 12:31:29 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static void	ft_calc_center_normal(t_cylinder *cy, t_vec3 *center,
							t_vec3 *normal, t_caps cap)
{
	if (cap == C_TOP)
	{
		*center = ft_vadd(cy->center, ft_vscalar(cy->axis, cy->height));
		*normal = cy->axis;
	}
	else
	{
		*center = cy->center;
		*normal = ft_vneg(cy->axis);
	}
}

static double	ft_calc_t(t_ray ray, t_vec3 normal, t_vec3 center, t_hit *hit)
{
	double	denom;
	double	t;

	denom = ft_vdot(ray.direction, normal);
	if (fabs(denom) < 1e-6)
		return (0);
	t = ft_vdot(ft_vsub(center, ray.origin), normal) / denom;
	if (t < 1e-6 || t > hit->t)
		return (0);
	return (t);
}

bool	ft_hit_cap(t_ray ray, t_cylinder *cy, t_hit *hit, t_caps cap)
{
	t_vec3	center;
	t_vec3	normal;
	double	t;
	t_vec3	point;
	t_vec3	vector;

	ft_calc_center_normal(cy, &center, &normal, cap);
	t = ft_calc_t(ray, normal, center, hit);
	if (t == 0)
		return (false);
	point = ft_ray_at(ray, t);
	vector = ft_vsub(point, center);
	if (ft_vdot(vector, vector) > cy->radius * cy->radius)
		return (false);
	if (t < hit->t)
	{
		hit->t = t;
		hit->point = point;
		hit->normal = normal;
		hit->mat = cy->material;
	}
	return (true);
}
