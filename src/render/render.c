/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:01:39 by asando            #+#    #+#             */
/*   Updated: 2026/08/24 23:48:29 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_build_camera_basis(t_camera *cam)
{
	t_vec3	global_up;

	cam->orientation = ft_vnormalize(cam->orientation);
	global_up = ft_vec3(0, 1, 0);
	cam->right = ft_vnormalize(ft_vcross(global_up, cam->orientation));
	cam->up = ft_vcross(cam->orientation, cam->right);
	return ;
}

static void	ft_setup_viewport(t_scene_rt *scene, double aspect)
{
	double	fov_rad;

	fov_rad = scene->camera.fov * M_PI / 180.0;
	scene->camera.vp_height = 2 * tan(fov_rad / 2);
	scene->camera.vp_width = scene->camera.vp_height * aspect;
	return ;
}

static t_ray	ft_generate_ray(t_scene_rt *scene, uint32_t x, uint32_t y)
{
	double	u;
	double	v;
	t_vec3	dir;

	u = (2 * ((x + 0.5) / WIDTH) - 1) * scene->camera.vp_width / 2;
	v = (1 - 2 * ((y + 0.5) / HEIGHT)) * scene->camera.vp_height / 2;
	dir = ft_vadd(ft_vadd(ft_vscalar(scene->camera.right, u),
				ft_vscalar(scene->camera.up, v)), scene->camera.orientation);
	return (ft_ray(scene->camera.position, ft_vnormalize(dir)));
}

static uint32_t	ft_to_rgb(t_vec3 color)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = (uint32_t)(color.x * 255.0);
	g = (uint32_t)(color.y * 255.0);
	b = (uint32_t)(color.z * 255.0);
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}

void	ft_render(t_mlx_interface *mlx_interface, t_scene_rt *scene)
{
	uint32_t	x;
	uint32_t	y;
	t_ray		ray;
	t_vec3		color;
	int			depth;

	x = 0;
	y = 0;
	depth = 0;
	ft_build_camera_basis(&scene->camera);
	ft_setup_viewport(scene, (double)WIDTH/HEIGHT);
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			ray = ft_generate_ray(scene, x, y);
			color = ft_trace(scene, ray, depth);
			ft_putpixel(mlx_interface->img, x, y, ft_to_rgb(color));
			x++;
		}
		x = 0;
		y++;
	}
}
