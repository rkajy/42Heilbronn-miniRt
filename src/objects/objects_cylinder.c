/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:04:02 by asando            #+#    #+#             */
/*   Updated: 2026/03/27 20:32:12 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

int	hit_cylinder(t_ray ray, t_cylinder *cy, t_hit *hit)
{
	t_vec3	oc;
	t_vec3	d;
	t_vec3	a;
	double	dv;
	double	ov;
	t_vec3	d_perp;
	t_vec3	oc_perp;
	double	A;
	double	B;
	double	C;
	double	disc;
	double	sqrt_d;
	double	t1;
	double	t2;
	double	t;
	t_vec3	p;
	double	h;

	oc = ft_vsub(ray.origin, cy->center);
	d = ray.direction;
	a = cy->axis;
	dv = ft_dot_mul(d, a);
	ov = ft_dot_mul(oc, a);
	d_perp = ft_vsub(d, ft_vmul(a, dv));
	oc_perp = ft_vsub(oc, ft_vmul(a, ov));
	return (1);
}
