/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:39:56 by radandri          #+#    #+#             */
/*   Updated: 2026/06/17 01:59:50 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include "../../include/parse.h"
#include "../../include/parse_functions.h"

static int	parse_cylinder_data(char **tokens, t_cylinder *cylinder,
		t_rt_error *error)
{
	if (parse_vec3(tokens[1], &cylinder->center, error) != RT_ERR_OK)
		return (error->code);
	if (parse_vec3(tokens[2], &cylinder->axis, error) != RT_ERR_OK)
		return (error->code);
	if (normalize_vector(&cylinder->axis, error) != RT_ERR_OK)
		return (error->code);
	if (parse_double(tokens[3], &cylinder->diameter, error) != RT_ERR_OK)
		return (error->code);
	if (validate_positive(cylinder->diameter, error) != RT_ERR_OK)
		return (error->code);
	if (parse_double(tokens[4], &cylinder->height, error) != RT_ERR_OK)
		return (error->code);
	if (validate_positive(cylinder->height, error) != RT_ERR_OK)
		return (error->code);
	return (RT_ERR_OK);
}

int	parse_cylinder(char **tokens, t_scene *scene, t_rt_error *error)
{
	t_cylinder	*cylinder;
	t_list		*node;

	if (validate_tokens(tokens, 6, error) != RT_ERR_OK)
		return (error->code);
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (parse_cylinder_data(tokens, cylinder, error) != RT_ERR_OK)
		return (free(cylinder), error->code);
	if (parse_color(tokens[5], &cylinder->material.color, error) != RT_ERR_OK)
		return (free(cylinder), error->code);
	node = ft_lstnew(cylinder);
	if (!node)
		return (free(cylinder), rt_error_set(error, RT_ERR_ALLOC));
	ft_lstadd_back(&scene->cylinders, node);
	return (RT_ERR_OK);
}
