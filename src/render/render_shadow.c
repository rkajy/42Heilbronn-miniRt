/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:39:27 by asando            #+#    #+#             */
/*   Updated: 2026/08/16 12:33:00 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static bool	ft_hit_sphere_true(t_scene_rt *scene, t_ray shadow_ray,
						t_hit *hit, double max_dist)
{
	size_t	i;

	i = 0;
	while (i < scene->nb_spheres)
	{
		if (ft_hit_sphere(shadow_ray, &scene->spheres[i], hit))
		{
			if (hit->t > 0.0 && hit->t < max_dist)
				return (true);
		}
		i++;
	}
	return (false);
}

static bool	ft_hit_plane_true(t_scene_rt *scene, t_ray shadow_ray,
						t_hit *hit, double max_dist)
{
	size_t	i;

	i = 0;
	while (i < scene->nb_planes)
	{
		if (ft_hit_plane(shadow_ray, &scene->planes[i], hit))
		{
			if (hit->t > 0.0 && hit->t < max_dist)
				return (true);
		}
		i++;
	}
	return (false);
}

static bool	ft_hit_cylinder_true(t_scene_rt *scene, t_ray shadow_ray,
						t_hit *hit, double max_dist)
{
	size_t	i;

	i = 0;
	while (i < scene->nb_cylinders)
	{
		if (ft_hit_cylinder(shadow_ray, &scene->cylinders[i], hit))
		{
			if (hit->t > 0.0 && hit->t < max_dist)
				return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_in_shadow(t_scene_rt *scene, t_vec3 point, t_light *light)
{
	t_vec3	light_dir;
	double	max_dist;
	t_ray	shadow_ray;
	t_hit	hit;

	light_dir = ft_vnormalize(ft_vsub(light->position, point));
	max_dist = ft_vmagnitude(ft_vsub(light->position, point));
	shadow_ray.origin = ft_vadd(point, ft_vscalar(light_dir, 1e-4));
	shadow_ray.direction = light_dir;
	if (ft_hit_sphere_true(scene, shadow_ray, &hit, max_dist))
		return (true);
	if (ft_hit_plane_true(scene, shadow_ray, &hit, max_dist))
		return (true);
	if (ft_hit_cylinder_true(scene, shadow_ray, &hit, max_dist))
		return (true);
	return (false);
}
