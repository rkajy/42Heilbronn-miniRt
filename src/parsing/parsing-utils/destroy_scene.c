/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:55:51 by radandri          #+#    #+#             */
/*   Updated: 2026/08/26 20:20:54 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdlib.h>

void	destroy_scene(t_scene *scene)
{
	ft_lstclear(&scene->ambients, free);
	ft_lstclear(&scene->cameras, free);
	ft_lstclear(&scene->cylinders, free);
	ft_lstclear(&scene->lights, free);
	ft_lstclear(&scene->planes, free);
	ft_lstclear(&scene->spheres, free);
}
