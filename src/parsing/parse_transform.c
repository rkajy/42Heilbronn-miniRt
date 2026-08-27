/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 22:15:30 by radandri          #+#    #+#             */
/*   Updated: 2026/08/27 18:07:24 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_functions.h"
#include "libft.h"

/*
** Optional transformations start disabled and use a zero vector.
** Example: an object without "T" keeps its original position.
*/
static void	init_transform(t_transform *transform)
{
	t_material	material;

	material.specular = 0.5;
	material.diffuse = 1.0;
	material.shininess = 32;
	material.reflective = 0.0;
	transform->translation = ft_vec3(0, 0, 0);
	transform->rotation = ft_vec3(0, 0, 0);
	transform->material = material;
	transform->has_translation = false;
	transform->has_rotation = false;
	transform->has_material = false;
}

/*
** A translation is read from the vector following the "T" token.
** Example: "T 1,0,0" moves the object one unit on the X axis.
*/
static int	parse_translation_token(char **tokens, int index,
			t_transform *transform, t_rt_error *error)
{
	if (ft_strncmp(tokens[index], "T", 2) != 0 || transform->has_translation
		|| !tokens[index + 1])
		return (0);
	if (parse_vec3(tokens[index + 1], &transform->translation, error)
		!= RT_ERR_OK)
		return (-1);
	transform->has_translation = true;
	return (2);
}

/*
** A rotation is read from the vector following the "R" token.
** Example: "R 0,90,0" rotates the object around the Y axis.
*/
static int	parse_rotation_token(char **tokens, int index,
			t_transform *transform, t_rt_error *error)
{
	if (ft_strncmp(tokens[index], "R", 2) != 0 || transform->has_rotation
		|| !tokens[index + 1])
		return (0);
	if (parse_vec3(tokens[index + 1], &transform->rotation, error)
		!= RT_ERR_OK)
		return (-1);
	transform->has_rotation = true;
	return (2);
}

static int	parse_material_token(char **tokens, int index,
			t_transform *transform, t_rt_error *error)
{
	if (ft_strncmp(tokens[index], "M", 2) != 0 || transform->has_material
		|| !tokens[index + 1])
		return (0);
	if (parse_material(tokens[index + 1], &transform->material, error)
		!= RT_ERR_OK)
		return (-1);
	transform->has_material = true;
	return (2);
}

int	parse_transformations(char **tokens, int index, t_transform *transform,
		t_rt_error *error)
{
	int	step;

	init_transform(transform);
	while (tokens[index])
	{
		step = parse_translation_token(tokens, index, transform, error);
		if (step == -1)
			return (error->code);
		if (step == 0)
			step = parse_rotation_token(tokens, index, transform, error);
		if (step == -1)
			return (error->code);
		if (step == 0)
			step = parse_material_token(tokens, index, transform, error);
		if (step == -1)
			return (error->code);
		if (step == 0)
			return (rt_error_set(error, RT_ERR_TRAILING_DATA));
		index += step;
	}
	return (RT_ERR_OK);
}
