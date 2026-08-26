/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:21:41 by asando            #+#    #+#             */
/*   Updated: 2026/08/26 21:45:16 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static void	ft_to_hit(t_constanta *con, t_ray ray, t_hit *hit, t_sphere *sp)
{
	hit->t = con->t;
	hit->point = ft_ray_at(ray, con->t);
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
	t1 = (-b - sqrt_d) / (2.0 * a);
	t2 = (-b + sqrt_d) / (2.0 * a);
	t = 1e30;
	if (t1 > 1e-06 && t1 < t)
		t = t1;
	if (t2 > 1e-06 && t2 < t)
		t = t2;
	return (t);
}

static double	ft_calc_disc(t_ray ray, t_sphere *sp, t_constanta *con)
{
	t_vec3	oc;
	double	radius;

	radius = sp->diameter / 2.0;
	oc = ft_vsub(ray.origin, sp->center);
	con->a = ft_vdot(ray.direction, ray.direction);
	con->b = 2.0 * ft_vdot(oc, ray.direction);
	con->c = ft_vdot(oc, oc) - radius * radius;
	return (con->b * con->b - 4.0 * con->a * con->c);
}

bool	ft_hit_sphere(t_ray ray, t_sphere *sp, t_hit *hit)
{
	double		t;
	double		discriminant;
	t_constanta	con;

	discriminant = ft_calc_disc(ray, sp, &con);
	if (discriminant < 0.0)
		return (false);
	t = ft_calc_t(discriminant, con.a, con.b);
	con.t = t;
	if (con.t < hit->t)
		ft_to_hit(&con, ray, hit, sp);
	else
		return (false);
	return (true);
}
