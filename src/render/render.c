/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:01:39 by asando            #+#    #+#             */
/*   Updated: 2026/08/09 13:14:50 by asando           ###   ########.fr       */
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
	dir = ft_vadd(ft_vadd(ft_vmul(scene->camera.right, u), 
					   ft_vmul(scene->camera.up, v)), scene->camera.orientation);
	res = ft_ray(scene->camera.position, dir);
	return (res);
}

void	ft_putpixel(mlx_image_t *img, uint32_t x, uint32_t y,
						uint32_t color)
{
	uint32_t	pixel_index;

	pixel_index = 0;
	if (x >= img->width || y >= img->height)
		return ;
	pixel_index = (y * img->width + x) * 4;
	img->pixels[pixel_index + 0] = (color >> 24) & 0xFF;
	img->pixels[pixel_index + 1] = (color >> 16) & 0XFF;
	img->pixels[pixel_index + 2] = (color >> 8) & 0XFF;
	img->pixels[pixel_index + 3] = (color >> 0) & 0XFF;
	return ;
}

uint32_t ft_to_rgb(t_vec3 color)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = (uint32_t)(color.x * 255.0);
	g = (uint32_t)(color.y * 255.0);
	b = (uint32_t)(color.z * 255.0);

	return (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

void	ft_render(t_scene_rt *scene)
{
	uint32_t	x;
	uint32_t	y;
	t_ray		ray;
	t_hit		hit;
	t_vec3		color;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			ray = ft_generate_ray(scene, x, y);
			color = ft_trace(scene, ray, &hit);
			ft_put_pixel(scene->img, x, y, ft_to_rgb(color));
			x++;
		}
		y++;
	}
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
	return ft_vsub(dir, ft_vmul(normal, 2.0 * ft_vdot(dir, normal)));
}

t_vec3	ft_vneg(t_vec3 v)
{
	return (ft_vec3(-v.x, -v.y, -v.z));
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

	i = 0;
	color = ft_vmul(hit->mat.color, scene->ambient);
	while (i < scene->nb_lights)
	{
		light = &scene->light[i];
		light_dir = ft_vnormalize(ft_vsub(light->position, hit->point));
		diff = fmax(0, ft_vdot(hit->normal, light_dir));
		reflect_dir = ft_reflect(ft_vneg(light_dir), hit->normal);
		spec = pow(fmax(0, ft_vdot(reflect_dir, ft_vneg(ray.direction))), hit->mat.specular);
		color = ft_vadd(color,
				  ft_vadd(
					ft_vmul(hit->mat.color, diff * light->intensity),
					ft_vmul(ft_vec3(1,1,1), spec * light->intensity)
				  )
				);
		i++;
	}
	return (ft_vclamp(color, 0, 255));
}
