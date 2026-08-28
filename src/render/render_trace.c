/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 22:16:56 by asando            #+#    #+#             */
/*   Updated: 2026/08/28 15:09:27 by asando           ###   ########.fr       */
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

static t_vec3	ft_refraction_color(t_scene_rt *scene, t_ray ray,
							t_hit closest, int depth)
{
	t_ray	refract_ray;
	t_vec3	refract_color;

	refract_color = ft_vec3(0, 0, 0);
	if (closest.mat.transparency > 0.0 && depth < REFLECT_DEPTH)
	{
		refract_ray.origin = ft_vsub(closest.point,
				ft_vscalar(closest.normal, 1e-04));
		refract_ray.direction = ft_refraction(ray.direction,
				closest.normal, closest.mat.ior);
		refract_color = ft_trace(scene, refract_ray, depth + 1);
	}
	return (refract_color);
}

static	t_vec3	ft_reflection_color(t_scene_rt *scene, t_ray ray,
							t_hit closest, int depth)
{
	t_ray	reflect_ray;
	t_vec3	reflect_color;

	reflect_color = ft_vec3(0, 0, 0);
	if (closest.mat.reflective > 0.0 && depth < REFLECT_DEPTH)
	{
		reflect_ray.origin = ft_vadd(closest.point,
				ft_vscalar(closest.normal, 1e-4));
		reflect_ray.direction = ft_vnormalize(ft_reflection(ray.direction,
					closest.normal));
		reflect_color = ft_trace(scene, reflect_ray, depth + 1);
	}
	return (reflect_color);
}

static t_vec3	ft_combine_color(t_ray ray, t_hit closest,
							t_vec3 reflect_color, t_vec3 refract_color)
{
	double	cosi;
	double	fresnel;
	t_vec3	final_color;

	cosi = fabs(ft_vdot(ray.direction, closest.normal));
	fresnel = ft_fresnel_schlick(cosi, closest.mat.ior);
	final_color = ft_vadd(
			ft_vscalar(reflect_color, fresnel),
			ft_vscalar(refract_color, 1.0 - fresnel));
	return (final_color);
}

t_vec3	ft_trace(t_scene_rt *scene, t_ray ray, int depth)
{
	t_vec3		color;
	t_vec3		reflect_color;
	t_vec3		refract_color;
	t_vec3		fresnel_color;
	t_hit		closest;

	closest.t = 1e30;
	if (ft_hit_object(scene, ray, &closest) == false)
		return (ft_vec3(0, 0, 0));
	color = ft_shade(scene, &closest, ray);
	reflect_color = ft_reflection_color(scene, ray, closest, depth);
	refract_color = ft_refraction_color(scene, ray, closest, depth);
	fresnel_color = ft_combine_color(ray, closest,
			reflect_color, refract_color);
	return (ft_vadd(ft_vscalar(color, 1.0 - closest.mat.transparency),
			ft_vscalar(fresnel_color, closest.mat.transparency)));
}
