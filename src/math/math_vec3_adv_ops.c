/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec3_adv_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:54:47 by asando            #+#    #+#             */
/*   Updated: 2026/08/22 01:14:22 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"

t_vec3	ft_reflection(t_vec3 ray_dir, t_vec3 v_normal)
{
	t_vec3	res;

	res = ft_vsub(ray_dir, ft_vscalar(v_normal, 2.0 * ft_vdot(ray_dir,
					v_normal)));
	return (res);
}

t_vec3	ft_translation(t_vec3 point, t_vec3 translate)
{
	return (ft_vadd(point, translate));
}

static double	to_radians(double degrees)
{
	return (degrees * M_PI / 180);
}

static t_vec3	ft_rotate_axis(t_vec3 v, double a, t_axis axis)
{
	t_vec3	res;

	if (axis == X_AXIS)
	{
		res.x = v.x;
		res.y = v.y * cos(to_radians(a)) - v.z * sin(to_radians(a));
		res.z = v.y * sin(to_radians(a)) + v.z * cos(to_radians(a));
	}
	else if (axis == Y_AXIS)
	{
		res.x = v.x * cos(to_radians(a)) + v.z * sin(to_radians(a));
		res.y = v.y;
		res.z = v.z * cos(to_radians(a)) - v.x * sin(to_radians(a));
	}
	else
	{
		res.x = v.x * cos(to_radians(a)) - v.y * sin(to_radians(a));
		res.y = v.x * sin(to_radians(a)) + v.y * cos(to_radians(a));
		res.z = v.z;
	}
	return (res);
}

t_vec3	ft_rotate(t_vec3 v, t_vec3 rotation)
{
	v = ft_rotate_axis(v, rotation.x, X_AXIS);
	v = ft_rotate_axis(v, rotation.y, Y_AXIS);
	v = ft_rotate_axis(v, rotation.z, Z_AXIS);
	return (v);
}
