/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:39:56 by radandri          #+#    #+#             */
/*   Updated: 2026/08/26 20:12:25 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parse.h"
#include "parse_functions.h"

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

static void	init_cylinder_material(t_material *material)
{
	material->specular = 0.5;
	material->diffuse = 1;
	material->shininess = 32;
	material->reflective = 0;
}

static int	parse_cylinder_transform(char **tokens, t_cylinder *cylinder,
		t_rt_error *error)
{
	t_transform	transform;

	if (parse_transformations(tokens, 6, &transform, error) != RT_ERR_OK)
		return (error->code);
	if (transform.has_translation)
		cylinder->center = ft_translation(cylinder->center,
				transform.translation);
	if (transform.has_rotation)
		cylinder->axis = ft_vnormalize(ft_rotate(cylinder->axis,
					transform.rotation));
	return (RT_ERR_OK);
}

int	parse_cylinder(char **tokens, t_scene *scene, t_rt_error *error)
{
	t_cylinder	*cylinder;
	t_list		*node;

	if (validate_min_tokens(tokens, 6, error) != RT_ERR_OK)
		return (error->code);
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (parse_cylinder_data(tokens, cylinder, error) != RT_ERR_OK)
		return (free(cylinder), error->code);
	init_cylinder_material(&cylinder->material);
	if (parse_color(tokens[5], &cylinder->material.color, error) != RT_ERR_OK)
		return (free(cylinder), error->code);
	if (parse_cylinder_transform(tokens, cylinder, error) != RT_ERR_OK)
		return (free(cylinder), error->code);
	node = ft_lstnew(cylinder);
	if (!node)
		return (free(cylinder), rt_error_set(error, RT_ERR_ALLOC));
	ft_lstadd_back(&scene->cylinders, node);
	return (RT_ERR_OK);
}
