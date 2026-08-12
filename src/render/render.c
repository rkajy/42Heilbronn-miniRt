/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:01:39 by asando            #+#    #+#             */
/*   Updated: 2026/08/12 20:35:17 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h";

void	ft_build_camera_basis(t_camera *cam)
{
	t_vec3	global_up;

	cam->orientation = ft_vnormalize(cam->orientiation);
	global_up = ft_vec3(0, 1, 0);
	cam->right = ft_vnomalize(ft_vcross(cam->orientation, global_up));
	cam->up = ft_vcross(cam->right, cam->orientation);
	return ;
}

void	ft_setup_viewport(t_scene_rt *scene, double aspect)
{
	double	fov_rad;

	fov_rad = scene->camera * M_PI / 180.0;
	scene->camera.vp_height = 2 * tan(fov_rad / 2);
	scene->camera.vp_width = scene->camera.vp_height * aspect;
}

t_ray	ft_generate_ray(t_scene_rt *scene, uint32_t x, uint32_t y)
{
	double	u;
	double	v;
	t_ray	res;
	t_vec3	dir;

	u = (2 * ((x + 0.5) / WIDTH) - 1) * scene->camera.vp_width / 2;
	v = (1 - 2 * ((y + 0.5) / HEIGHT)) * scene->camera.vp_height / 2;
	dir = ft_vadd(ft_vadd(ft_vscalar(scene->camera.right, u), 
					   ft_vscalar(scene->camera.up, v)), scene->camera.orientation);
	res = ft_ray(scene->camera.position, dir);
	return (res);
}

t_vec3	ft_trace(t_scene_rt_rt *scene, t_ray ray, t_hit *closest)
{
	bool		hit_anything;
	size_t		i;

	closest->t = 1e30;
	hit_anything = false;
	i = 0;
	while (i < scene->nb_spheres)
	{
		if (ft_hit_sphere(ray, &scene->spheres[i], closest))
			hit_anything = true;
		i++;
	}
	i = 0;
	while (i < scene->nb_planes)
	{
		if (ft_hit_plane(ray, &scene->planes[i], closest))
			hit_anything = true;
		i++;
	}
	i = 0;
	while (i < scene->nb_cylinders)
	{
		if (ft_hit_cylinder(ray, &scene->cylinders[i], closest))
			hit_anything = true;
		i++;
	}
	if (hit_anything == false)
		return (ft_vec3(0, 0, 0));
	return (ft_shade(scene, closest, ray));
}

t_vec3	ft_reflection(t_vec3 dir, t_vec3 normal)
{
	return ft_vsub(dir, ft_vscalar(normal, 2.0 * ft_vdot(dir, normal)));
}

t_vec3	ft_shade(t_scene_rt *scene, t_hit *hit, t_ray ray)
{
	t_vec3	color;
	size_t	i;
	t_light	*light;
	t_vec3	light_dir;
	double	diff;
	t_vec3	reflect_dir;
	double	spec;
	double	spec_angle;

	i = 0;
	color = ft_vscalar(hit->mat.color, scene->ambient.ratio);
	while (i < scene->nb_lights)
	{
		light = &scene->lights[i];
		if (ft_in_shadow(scene, hit->point, light))
			continue ;
		light_dir = ft_vnormalize(ft_vsub(light->position, hit->point));
		diff = fmax(0.0, ft_vdot(hit->normal, light_dir));
		diff *= hit->mat.diffuse;
		reflect_dir = ft_reflect(ft_vneg(light_dir), hit->normal);
		spec_angle = fmax(0.0, ft_vdot(reflect_dir, ft_vneg(ray.direction)));
		spec = pow(spec_angle, hit->mat.shininess);
		spec *= hit->mat.specular;
		color = ft_vadd(color,
				  ft_vadd(
					ft_vscalar(hit->mat.color, diff * light->brightness),
					ft_vscalar(ft_vec3(1,1,1), spec * light->brightness)
				  )
				);
		i++;
	}
	return (ft_vclamp(color, 0, 1.0));
}

bool	ft_in_shadow(t_scene_rt *scene, t_vec3 point, t_light *light)
{
	t_vec3	light_dir;
	double	max_dist;
	t_ray	shadow_ray;
	t_hit	hit;
	size_t	i;

	light_dir = ft_vnormalize(ft_vsub(light->position, point));
	max_dist = ft_vmagnitude(ft_vsub(light->position, point));
	shadow_ray.origin = ft_vadd(point, ft_vscalar(light_dir, 1e-4));
	shadow_ray.direction = light_dir;
	i = 0;
	while (i < scene->nb_spheres)
	{
		if (ft_hit_sphere(shadow_ray, &scene->spheres[i], &hit))
		{
			if (hit.t > 0.0 && hit.t < max_dist)
				return (true);
		}
		i++;
	}
	i = 0;
	while (i < scene->nb_planes)
	{
		if (ft_hit_plane(shadow_ray, &scene->planes[i], &hit))
		{
			if (hit.t > 0.0 && hit.t < max_dist)
				return (true);
		}
		i++;
	}
	i = 0;
	while (i < scene->nb_cylinders)
	{
		if (ft_hit_cylinder(shadow_ray, &scene->cylinders[i], &hit))
		{
			if (hit.t > 0.0 && hit.t < max_dist)
				return (true);
		}
		i++;
	}
	return (false);
}
