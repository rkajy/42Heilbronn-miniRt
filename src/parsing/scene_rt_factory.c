/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_rt_factory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 19:43:15 by radandri          #+#    #+#             */
/*   Updated: 2026/07/12 21:17:43 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"
#include <stdbool.h>

static void	copy_spheres(t_scene_rt *dst, t_list *lst)
{
	while (lst && dst->nb_spheres < MAX_SPHERES)
	{
		dst->spheres[dst->nb_spheres++] = *(t_sphere *)lst->content;
		lst = lst->next;
	}
}

static void	copy_planes(t_scene_rt *dst, t_list *lst)
{
	while (lst && dst->nb_planes < MAX_PLANES)
	{
		dst->planes[dst->nb_planes++] = *(t_plane *)lst->content;
		lst = lst->next;
	}
}

static void	copy_cylinders(t_scene_rt *dst, t_list *lst)
{
	while (lst && dst->nb_cylinders < MAX_CYLINDERS)
	{
		dst->cylinders[dst->nb_cylinders++] = *(t_cylinder *)lst->content;
		lst = lst->next;
	}
}

bool	scene_rt_factory(const t_scene *src, t_scene_rt *dst)
{
	ft_bzero(dst, sizeof(*dst));
	copy_spheres(dst, src->spheres);
	copy_planes(dst, src->planes);
	copy_cylinders(dst, src->cylinders);
	dst->camera = *(t_camera *)src->cameras->content;
	dst->ambient = *(t_ambient *)src->ambients->content;
	dst->light = *(t_light *)src->lights->content;
	return (true);
}
