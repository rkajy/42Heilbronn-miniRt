/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 04:04:22 by radandri          #+#    #+#             */
/*   Updated: 2026/08/17 15:26:08 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include "../../include/parse.h"

int	validate_scene(t_scene *scene, t_rt_error *error)
{
	if (scene->ambients == NULL)
		return (rt_error_set(error, RT_ERR_MISSING_AMBIENT));
	if (scene->cameras == NULL)
		return (rt_error_set(error, RT_ERR_MISSING_CAMERA));
	if (scene->lights == NULL)
		return (rt_error_set(error, RT_ERR_MISSING_LIGHT));
	if (scene->spheres == NULL && scene->planes == NULL
		&& scene->cylinders == NULL)
		return (rt_error_set(error, RT_ERR_INVALID_FORMAT));
	return (RT_ERR_OK);
}
