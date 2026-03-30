/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:01:39 by asando            #+#    #+#             */
/*   Updated: 2026/03/30 19:00:04 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h";

void	ft_build_camera_basis(t_camere *cam)
{
	t_vec3	global_up;

	cam->dir = ft_vnormalize(cam->dir);
	global_up = ft_vec3(0, 1, 0);
	cam->right = ft_vnomalize(ft_vcross(cam->dir, global_up));
	cam->up = ft_vcross(cam->right, cam->dir);
	return ;
}

void	ft_setup_viewport(t_scene *scene, double aspect)
{
	double	fov_rad;

	fov_rad = scene->camera * M_PI / 180.0;
	scene->vp_height = 2 * tan(fov_rad / 2);
	scene->vp_width = scene->vp_height * aspect;
}

t_ray	ft_generate_ray(t_scene *scene, int x, int y)
{
	double	u;
	double	v;
	t_ray	res;
	t_vec3	dir;

	u = (2 * ((x + 0.5) / WIDTH) - 1) * scene->vp_width / 2;
	v = (1 - 2 * ((y + 0.5) / HEIGHT)) * scene->vp_height / 2;
	dir = ft_vadd(ft_vadd(ft_vmul(scene->camera.right, u), 
					   ft_vmul(scene->camera.up, v)), scene->camera.dir);
	res = ft_ray(scene->camera.pos, dir);
	return (res);
}

void	ft_render(t_scene *scene)
{
	int		x;
	int		y;
	t_ray	ray;
	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			ray = ft_generate_ray(scene, x, y);
			//TODO: Put pixel and color here
			x++;
		}
		y++;
	}
}
