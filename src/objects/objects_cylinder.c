/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:04:02 by asando            #+#    #+#             */
/*   Updated: 2026/08/14 14:21:34 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static int	ft_to_hit(t_constanta con, t_ray ray, t_hit *hit, t_cylinder *cy)
{
	t_vec3	p;
	t_vec3	proj;
	double	h;

	p = ft_ray_at(ray, con.t);
	h = ft_vdot(ft_vsub(p, cy->center), con.a);
	if (h < 0 || h > cy->height)
		return (0);
	hit->t = con.t;
	hit->point = p;
	proj = ft_vadd(cy->center, ft_vscalar(con.a, h));
	hit->normal = ft_vnomalize(ft_vsub(p, proj));
	hit->mat = cy->material;
	return (1);
}

static double	ft_calc_t(double discriminant, double a, double b)
{
	double	t1;
	double	t2;
	double	t;
	double	sqrt_d;

	sqrt_d = sqrt(discriminant);
	t1 = (-b - sqrt_d) / (2 * a);
	t1 = (-b + sqrt_d) / (2 * a);
	if (t1 > 1e-06)
		t = t1;
	else
		t = t2;
	return (t);
}

static double	ft_calc_disc(t_ray ray, t_cylinder *cy, t_constanta con)
{
	t_vec3	oc;
	double	dv;
	double	ov;
	double	d_perp;
	double	oc_perp;

	oc = ft_vsub(ray.origin, cy->center);
	dv = ft_vdot(ray.direction, cy->axis);
	ov = ft_vdot(oc, cy->axis);
	d_perp = ft_vsub(ray.direction, ft_vscalar(cy->axis, dv));
	oc_perp = ft_vsub(oc, ft_vscalar(cy->axis, ov));
	con.a = ft_vdot(d_perp, d_perp);
	con.b = 2 * ft_vdot(d_perp, oc_perp);
	con.c = ft_vdot(oc_perp, oc_perp) - cy->radius * cy->radius;
	return (con.b * con.b - 4 * con.a * con.c);
}

int	ft_hit_cylinder(t_ray ray, t_cylinder *cy, t_hit *hit)
{
	double		discriminant;
	double		t;
	t_constanta	con;
	int			hit_any;

	hit_any = 0;
	discriminant = ft_calc_disc(ray, cy, con);
	if (discriminant >= 0)
	{
		t = ft_calc_t(discriminant, con.a, con.b);
		if (t > 1e-06)
		{
			con.t = t;
			if (ft_to_hit(con, ray, hit, cy) == 0)
				hit_any = 1;
		}
	}
	if (ft_hit_cap(ray, cy, hit, C_BOTTOM))
		hit_any = 1;
	if (ft_hit_cap(ray, cy, hit, C_TOP))
		hit_any = 1;
	return (hit_any);
}
