/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec3_adv_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:54:47 by asando            #+#    #+#             */
/*   Updated: 2026/08/20 22:52:34 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"

t_vec3	ft_reflection(t_vec3 ray_dir, t_vec3 v_normal)
{
	t_vec3	res;

	res = ft_vsub(ray_dir,
			ft_vscalar(v_normal, 2.0 * ft_vdot(ray_dir, v_normal)));
	return (res);
}

t_vec3	ft_translation(t_vec3 point, t_vec3 translate)
{
	return (ft_vadd(point, translate));
}

static t_vec3	ft_rotate_axis(t_vec3 v, double a, t_axis axis)
{
	t_vec3	res;

	if (axis == X_AXIS)
	{
		res.x = v.x;
		res.y = v.y * cos(a) - v.z * sin(a);
		res.z = v.y * sin(a) + v.z * cos(a);
	}
	else if (axis == Y_AXIS)
	{
		res.x = v.x * cos(a) + v.z * sin(a);
		res.y = v.y;
		res.z = v.z * cos(a) - v.x * sin(a);
	}
	else
	{
		res.x = v.x * cos(a) - v.y * sin(a);
		res.y = v.x * sin(a) + v.y * cos(a);
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
