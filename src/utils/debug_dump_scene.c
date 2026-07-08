/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_dump_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:40:00 by radandri          #+#    #+#             */
/*   Updated: 2026/07/09 00:31:33 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"
#include <stdio.h>

static void	debug_dump_ambients(t_list *node)
{
	t_ambient	*ambient;
	int			i;

	i = 0;
	while (node)
	{
		ambient = (t_ambient *)node->content;
		printf("  ambient[%d]: ratio=%.6f ", i, ambient->ratio);
		printf("color=(%.0f, %.0f, %.0f)\n", ambient->color.r,
			ambient->color.g, ambient->color.b);
		node = node->next;
		i++;
	}
}

static void	debug_dump_cameras(t_list *node)
{
	t_camera	*camera;
	int			i;

	i = 0;
	while (node)
	{
		camera = (t_camera *)node->content;
		printf("  camera[%d]: position=(%.6f, %.6f, %.6f) ", i,
			camera->position.x, camera->position.y, camera->position.z);
		printf("orientation=(%.6f, %.6f, %.6f) fov=%.6f\n",
			camera->orientation.x, camera->orientation.y,
			camera->orientation.z, camera->fov);
		node = node->next;
		i++;
	}
}

static void	debug_dump_lights(t_list *node)
{
	t_light	*light;
	int		i;

	i = 0;
	while (node)
	{
		light = (t_light *)node->content;
		printf("  light[%d]: position=(%.6f, %.6f, %.6f) ", i,
			light->position.x, light->position.y, light->position.z);
		printf("brightness=%.6f color=(%.0f, %.0f, %.0f)\n",
			light->brightness, light->color.r, light->color.g,
			light->color.b);
		node = node->next;
		i++;
	}
}

static void	debug_dump_counts(const t_scene *scene)
{
	printf("counts: ambients=%d cameras=%d lights=%d spheres=%d ",
		ft_lstsize(scene->ambients), ft_lstsize(scene->cameras),
		ft_lstsize(scene->lights), ft_lstsize(scene->spheres));
	printf("planes=%d cylinders=%d\n", ft_lstsize(scene->planes),
		ft_lstsize(scene->cylinders));
}

void	debug_dump_scene(const t_scene *scene)
{
	printf("\n=== t_scene dump ===\n");
	debug_dump_counts(scene);
	debug_dump_ambients(scene->ambients);
	debug_dump_cameras(scene->cameras);
	debug_dump_lights(scene->lights);
	debug_dump_spheres(scene->spheres);
	debug_dump_planes(scene->planes);
	debug_dump_cylinders(scene->cylinders);
	printf("====================\n\n");
}
