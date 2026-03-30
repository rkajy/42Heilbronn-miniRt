/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:01:39 by asando            #+#    #+#             */
/*   Updated: 2026/03/30 14:10:27 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
