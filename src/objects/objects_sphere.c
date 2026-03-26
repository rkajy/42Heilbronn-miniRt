/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:21:41 by asando            #+#    #+#             */
/*   Updated: 2026/03/26 21:43:14 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static void	ft_to_hit(double t, t_ray ray, t_hit *hit, t_speher *sp)
{
	hit->t = t;
	hit->point = ft_ray_at(ray, t);
	hit->normal = ft_vnormalize(ft_vsub(hit->point, sp->center));
	hit->mat = sp->mat;
	return ;
}

static double	ft_calc_t(double discriminant, double a, double b)
{
	double	sqrt_d;
	double	t1;
	double	t2;
	double	t;

	sqrt_d = sqrt(discriminant);
	t1 = (-b - sqrt_d) / (2 * a);
	t2 = (-b + sqrt_d) / (2 * a);
	if (t1 > 1e-06)
		t = t1;
	else
		t = t2;
	return (t);
}

int	hit_sphere(t_ray ray, t_sphere *sp, t_hit *hit)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = ft_dot_mul(ray.direction, ray.direction);
	b = 2.0 * ft_dot_mul(oc, ray.direction);
	c = ft_dot_mul(oc, oc) - sp->radius * sp->radius;
	discriminant = b * b - 4 * a * c;
	oc = ft_vsub(ray.origin, sp->center);
	if (discriminant == 0)
		return (0);
	t = ft_calc_t(discriminant, a, b);
	if (t < 1e-06)
		return (0);
	return (1);
}
