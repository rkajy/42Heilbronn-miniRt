/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_dump_shapes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:48:00 by radandri          #+#    #+#             */
/*   Updated: 2026/07/12 19:38:39 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse.h"
#include <stdio.h>

void	debug_dump_spheres(t_list *node)
{
	t_sphere	*sphere;
	int			i;

	i = 0;
	while (node)
	{
		sphere = (t_sphere *)node->content;
		printf("  sphere[%d]: center=(%.6f, %.6f, %.6f) ", i, sphere->center.x,
			sphere->center.y, sphere->center.z);
		printf("diameter=%.6f color=(%.0f, %.0f, %.0f)\n", sphere->diameter,
			sphere->material.color.r, sphere->material.color.g,
			sphere->material.color.b);
		node = node->next;
		i++;
	}
}

void	debug_dump_planes(t_list *node)
{
	t_plane	*plane;
	int		i;

	i = 0;
	while (node)
	{
		plane = (t_plane *)node->content;
		printf("  plane[%d]: point=(%.6f, %.6f, %.6f) ", i, plane->point.x,
			plane->point.y, plane->point.z);
		printf("normal=(%.6f, %.6f, %.6f) color=(%.0f, %.0f, %.0f)\n",
			plane->normal.x, plane->normal.y, plane->normal.z,
			plane->material.color.r, plane->material.color.g,
			plane->material.color.b);
		node = node->next;
		i++;
	}
}

void	debug_dump_cylinders(t_list *node)
{
	t_cylinder	*cylinder;
	int			i;

	i = 0;
	while (node)
	{
		cylinder = (t_cylinder *)node->content;
		printf("  cylinder[%d]: center=(%.6f, %.6f, %.6f) ", i,
			cylinder->center.x, cylinder->center.y, cylinder->center.z);
		printf("axis=(%.6f, %.6f, %.6f) diameter=%.6f height=%.6f ",
			cylinder->axis.x, cylinder->axis.y, cylinder->axis.z,
			cylinder->diameter, cylinder->height);
		printf("color=(%.0f, %.0f, %.0f)\n", cylinder->material.color.r,
			cylinder->material.color.g, cylinder->material.color.b);
		node = node->next;
		i++;
	}
}
