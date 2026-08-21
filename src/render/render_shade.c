/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shade.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:56:02 by asando            #+#    #+#             */
/*   Updated: 2026/08/16 12:40:24 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_vec3	ft_color_vec(t_color color)
{
	return (ft_vec3(color.r / 255.0, color.g / 255.0, color.b / 255.0));
}

static double	ft_specular_calc(t_hit *hit, t_ray ray, t_light *light)
{
	double	spec;
	t_vec3	reflect_dir;
	double	spec_angle;
	t_vec3	light_dir;

	light_dir = ft_vnormalize(ft_vsub(light->position, hit->point));
	reflect_dir = ft_reflection(ft_vneg(light_dir), hit->normal);
	spec_angle = fmax(0.0, ft_vdot(reflect_dir, ft_vneg(ray.direction)));
	spec = pow(spec_angle, hit->mat.shininess);
	spec *= hit->mat.specular;
	return (spec);
}

static double	ft_diffuse_calc(t_hit *hit, t_light *light)
{
	double	diff;
	t_vec3	light_dir;

	light_dir = ft_vnormalize(ft_vsub(light->position, hit->point));
	diff = fmax(0.0, ft_vdot(hit->normal, light_dir));
	diff *= hit->mat.diffuse;
	return (diff);
}

static t_vec3	ft_add_diff_specular(t_hit *hit, double diff,
						double spec, t_light *light)
{
	t_vec3	final_vec;

	final_vec = ft_vadd(ft_vscalar(ft_color_vec(hit->mat.color),
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
	color = ft_vscalar(ft_color_vec(hit->mat.color), scene->ambient.ratio);
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
