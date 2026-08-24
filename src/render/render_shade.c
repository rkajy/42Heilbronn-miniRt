/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shade.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:56:02 by asando            #+#    #+#             */
/*   Updated: 2026/08/25 00:21:01 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_vec3	ft_color_to_vec(t_color c)
{
	return (ft_vec3(c.r / 255.0, c.g / 255.0, c.b / 255.0));
}

static double	ft_specular_calc(t_hit *hit, t_ray ray, t_light *light)
{
	double	spec;
	t_vec3	reflect_dir;
	double	spec_angle;
	t_vec3	light_dir;

	light_dir = ft_vnormalize(ft_vsub(light->position, hit->point));
	reflect_dir = ft_vnormalize(ft_reflection(light_dir, hit->normal));
	spec_angle = fmax(0.0, ft_vdot(reflect_dir, ft_vneg(ray.direction)));
	spec = pow(spec_angle, hit->mat.shininess);
	return (spec * hit->mat.specular);
}

static double	ft_diffuse_calc(t_hit *hit, t_light *light)
{
	double	diff;
	t_vec3	light_dir;

	light_dir = ft_vnormalize(ft_vsub(light->position, hit->point));
	diff = fmax(0.0, ft_vdot(hit->normal, light_dir));
	return (diff * hit->mat.diffuse);
}

static t_vec3	ft_add_diff_specular(t_hit *hit, double diff,
						double spec, t_light *light)
{
	t_vec3	final_vec;

	final_vec = ft_vadd(ft_vscalar(ft_color_to_vec(hit->mat.color),
									diff * light->brightness),
			ft_vscalar(ft_vec3(1, 1, 1), spec * light->brightness));
	return (final_vec);
}

t_vec3	ft_shade(t_scene_rt *scene, t_hit *hit, t_ray ray)
{
	t_vec3	color;
	size_t	i;
	t_light	*light;
	double	diff;
	double	spec;

	i = 0;
	color = ft_vscalar(ft_color_to_vec(scene->ambient.material.color),
						scene->ambient.ratio);
	while (i < scene->nb_lights)
	{
		light = &scene->lights[i];
		if (ft_in_shadow(scene, hit->point, light))
		{
			i++;
			continue ;
		}
		diff = ft_diffuse_calc(hit, light);
		spec = ft_specular_calc(hit, ray, light);
		color = ft_vadd(color, ft_add_diff_specular(hit, diff, spec, light));
		i++;
	}
	return (ft_vclamp(color, 0, 1.0));
}
