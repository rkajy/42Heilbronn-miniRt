/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:06:03 by asando            #+#    #+#             */
/*   Updated: 2026/08/24 22:58:42 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"

t_ray	ft_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = ft_vnormalize(direction);
	return (ray);
}

t_vec3	ft_ray_at(t_ray ray, double t)
{
	t_vec3	res;

	res = ft_vadd(ray.origin, ft_vscalar(ray.direction, t));
	return (res);
}
