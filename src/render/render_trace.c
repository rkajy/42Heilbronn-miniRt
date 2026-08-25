/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 22:16:56 by asando            #+#    #+#             */
/*   Updated: 2026/08/25 21:11:48 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static bool	ft_hit_object(t_scene_rt *scene, t_ray ray, t_hit *closest)
{
	bool		hit_anything;
	size_t		i;

	hit_anything = false;
	i = 0;
	while (i < scene->nb_spheres)
	{
		if (ft_hit_sphere(ray, &scene->spheres[i++], closest))
			hit_anything = true;
	}
	i = 0;
	while (i < scene->nb_planes)
	{
		if (ft_hit_plane(ray, &scene->planes[i++], closest))
			hit_anything = true;
	}
	i = 0;
	while (i < scene->nb_cylinders)
	{
		if (ft_hit_cylinder(ray, &scene->cylinders[i++], closest))
			hit_anything = true;
	}
	return (hit_anything);
}

t_vec3	ft_trace(t_scene_rt *scene, t_ray ray, int depth)
{
	t_vec3		color;
	t_ray		reflect_ray;
	t_vec3		reflect_color;
	t_hit		closest;

	closest.t = 1e30;
	if (ft_hit_object(scene, ray, &closest) == false)
		return (ft_vec3(0, 0, 0));
	color = ft_shade(scene, &closest, ray);
	if (closest.mat.reflective > 0.0 && depth < REFLECT_DEPTH)
	{
		reflect_ray.origin = ft_vadd(closest.point,
				ft_vscalar(closest.normal, 1e-4));
		reflect_ray.direction = ft_vnormalize(ft_reflection(ray.direction,
					closest.normal));
		reflect_color = ft_trace(scene, reflect_ray, depth + 1);
		color = ft_vadd(
				ft_vscalar(color, 1.0 - closest.mat.reflective),
				ft_vscalar(reflect_color, closest.mat.reflective)
				);
	}
	return (color);
}
