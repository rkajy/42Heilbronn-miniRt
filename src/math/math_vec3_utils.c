/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec3_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:34:04 by asando            #+#    #+#             */
/*   Updated: 2026/08/09 14:36:56 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathrt.h"

double	ft_vmagnitude(t_vec3 v)
{
	double	res;
	double	dot_product;

	dot_product = ft_vdot(v, v);
	res = sqrt(dot_product);
	return (res);
}

t_vec3	ft_vnormalize(t_vec3 v)
{
	double	v_magnitude;
	t_vec3	res;

	v_magnitude = ft_vmagnitude(v);
	if (v_magnitude == 0)
		res = ft_vec3(0, 0, 0);
	else
		res = ft_vscalar(v, 1.0/v_magnitude);
	return (res);
}

t_vec3	ft_velement_mul(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = v1.x * v2.x;
	res.y = v1.y * v2.y;
	res.z = v1.z * v2.z;
	return (res);
}

t_vec3	ft_vclamp(t_vec3 v, double min, double max)
{
	if (v.x < min)
		v.x = min;
	if (v.y < min)
		v.y = min;
	if (v.z < min)
		v.z = min;
	if (v.x > max)
		v.x = max;
	if (v.y > max)
		v.y = max;
	if (v.z > max)
		v.z = max;
	return (v);
}

t_vec3	ft_vneg(t_vec3 v)
{
	return (ft_vec3(-v.x, -v.y, -v.z));
}
