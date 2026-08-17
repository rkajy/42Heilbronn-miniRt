/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:45:50 by radandri          #+#    #+#             */
/*   Updated: 2026/06/17 02:01:33 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include "../../include/parse.h"
#include "../../include/parse_functions.h"

int	parse_plane(char **tokens, t_scene *scene, t_rt_error *error)
{
	t_plane	*plane;
	t_list	*node;

	if (validate_tokens((char **)tokens, 4, error) != RT_ERR_OK)
		return (error->code);
	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (parse_vec3(tokens[1], &plane->point, error) != RT_ERR_OK)
		return (free(plane), error->code);
	if (parse_vec3(tokens[2], &plane->normal, error) != RT_ERR_OK)
		return (free(plane), error->code);
	if (normalize_vector(&plane->normal, error) != RT_ERR_OK)
		return (free(plane), error->code);
	plane->material.specular = 0.5;
	plane->material.diffuse = 1;
	plane->material.shininess = 32;
	plane->material.reflective = 0;
	if (parse_color(tokens[3], &plane->material.color, error) != RT_ERR_OK)
		return (free(plane), error->code);
	node = ft_lstnew(plane);
	if (!node)
		return (free(plane), rt_error_set(error, RT_ERR_ALLOC));
	ft_lstadd_back(&scene->planes, node);
	return (RT_ERR_OK);
}
