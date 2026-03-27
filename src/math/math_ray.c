/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:06:03 by asando            #+#    #+#             */
/*   Updated: 2026/03/27 20:39:35 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathrt.h"

t_ray	ft_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = ft_vnormalize(direction);
	return (ray);
}

t_ray	ft_ray_at(t_ray ray, double t)
{
	t_ray	res;

	res = ray.origin + ft_vscalar(ray.direction, t);
	return (res);
}
