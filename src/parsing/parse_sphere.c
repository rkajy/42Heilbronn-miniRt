/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:01:45 by radandri          #+#    #+#             */
/*   Updated: 2026/07/09 00:47:02 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include "../../include/parse.h"
#include "../../include/parse_functions.h"

int	parse_sphere(char **tokens, t_scene *scene, t_rt_error *error)
{
	t_sphere	*sphere;
	t_list		*node;

	if (validate_tokens((char **)tokens, 4, error) != RT_ERR_OK)
		return (error->code);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (parse_vec3(tokens[1], &sphere->center, error) != RT_ERR_OK)
		return (free(sphere), error->code);
	if (parse_double(tokens[2], &sphere->diameter, error) != RT_ERR_OK)
		return (free(sphere), error->code);
	if (validate_positive(sphere->diameter, error) != RT_ERR_OK)
		return (free(sphere), error->code);
	if (parse_color(tokens[3], &sphere->material.color, error) != RT_ERR_OK)
		return (free(sphere), error->code);
	node = ft_lstnew(sphere);
	if (!node)
		return (free(sphere), rt_error_set(error, RT_ERR_ALLOC));
	ft_lstadd_back(&scene->spheres, node);
	return (RT_ERR_OK);
}
