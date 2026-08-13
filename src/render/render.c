/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:01:39 by asando            #+#    #+#             */
/*   Updated: 2026/08/13 22:14:50 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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

t_vec3	ft_trace(t_scene_rt_rt *scene, t_ray ray, , int depth)
{
	bool		hit_anything;
	size_t		i;
	t_vec3		color;
	t_ray		reflect_ray;
	t_vec3		reflect_color;
	t_hit		closest;

	closest->t = 1e30;
	hit_anything = false;
	i = 0;
	while (i < scene->nb_spheres)
	{
		if (ft_hit_sphere(ray, &scene->spheres[i], &closest))
			hit_anything = true;
		i++;
	}
	i = 0;
	while (i < scene->nb_planes)
	{
		if (ft_hit_plane(ray, &scene->planes[i], &closest))
			hit_anything = true;
		i++;
	}
	i = 0;
	while (i < scene->nb_cylinders)
	{
		if (ft_hit_cylinder(ray, &scene->cylinders[i], &closest))
			hit_anything = true;
		i++;
	}
	if (hit_anything == false)
		return (ft_vec3(0, 0, 0));

	color = ft_shade(scene, &closest, ray);
	if (closest.mat.reflective > 0.0 && depth < REFLECT_DEPTH)
	{
		reflect_ray.origin = ft_vadd(closest.point, ft_vscalar(closest.normal, 1e-4));
		reflect_ray.direction = ft_vnormalize(ft_reflect(ray.direction, closest.normal));
		reflect_color = ft_trace(scene, reflect_ray, depth + 1);
		color = ft_vadd(
			ft_vscalar(color, 1.0 - closest.mat.reflective),
			ft_vscalar(reflect_color, closest.mat.reflective)
		);

	}
	return (color);
}

t_vec3	ft_reflection(t_vec3 dir, t_vec3 normal)
{
	return ft_vsub(dir, ft_vscalar(normal, 2.0 * ft_vdot(dir, normal)));
}
