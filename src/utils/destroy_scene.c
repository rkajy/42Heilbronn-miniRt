/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:55:51 by radandri          #+#    #+#             */
/*   Updated: 2026/07/07 01:08:43 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"
#include "../../lib/libft/includes/libft.h"
#include <stdlib.h>

void    destroy_scene(t_scene *scene)
{
    ft_lstclear(&scene->ambients, free);
    ft_lstclear(&scene->cameras, free);
    ft_lstclear(&scene->cylinders, free);
    ft_lstclear(&scene->lights, free);
    ft_lstclear(&scene->planes, free);
    ft_lstclear(&scene->spheres, free);
}