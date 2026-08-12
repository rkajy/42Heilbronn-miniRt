/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:21:41 by asando            #+#    #+#             */
/*   Updated: 2026/08/12 19:52:22 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static void	ft_to_hit(t_constanta con, t_ray ray, t_hit *hit, t_speher *sp)
{
	hit->t = con.t;
	hit->point = ft_ray_at(ray, con.t);
	hit->normal = ft_vnormalize(ft_vsub(hit->point, sp->center));
	hit->mat = sp->material;
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

static double	ft_calc_disc(t_ray ray, t_sphere *sp, t_constanta con)
{
	t_vec3	oc;

	oc = ft_vsub(ray.origin, sp->center);
	con.a = ft_vdot(ray.direction, ray.direction);
	con.b = 2.0 * ft_vdot(oc, ray.direction);
	con.c = ft_vdot(oc, oc) - sp->radius * sp->radius;
	return (con.b * con.b - 4 * con.a * con.c);
}

int	ft_hit_sphere(t_ray ray, t_sphere *sp, t_hit *hit)
{
	double		t;
	double		discriminant;
	t_constanta	con;

	discriminant = ft_calc_disc(ray, sp, con);
	if (discriminant == 0)
		return (0);
	t = ft_calc_t(discriminant, con.a, con.b);
	if (t < 1e-06)
		return (0);
	con.t = t;
	ft_to_hit(con, ray, hit, sp);
	return (1);
}
