/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:45:50 by radandri          #+#    #+#             */
/*   Updated: 2026/08/26 20:14:43 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parse.h"
#include "parse_functions.h"

/*
** A plane needs a point and a normal before its color is parsed.
** Example: "pl 0,0,0 0,1,0 255,255,255" faces upward.
*/
static int	parse_plane_data(char **tokens, t_plane *plane, t_rt_error *error)
{
	if (parse_vec3(tokens[1], &plane->point, error) != RT_ERR_OK)
		return (error->code);
	if (parse_vec3(tokens[2], &plane->normal, error) != RT_ERR_OK)
		return (error->code);
	if (normalize_vector(&plane->normal, error) != RT_ERR_OK)
		return (error->code);
	return (RT_ERR_OK);
}

static void	init_plane_material(t_material *material)
{
	material->specular = 0.5;
	material->diffuse = 1;
	material->shininess = 32;
	material->reflective = 0;
	material->transparency = 0.0;
	material->ior = 1.5;
}

/*
** Translation changes the plane point; rotation changes its normal.
** Example: "T 0,2,0 R 0,0,90" applies both optional transforms.
*/
static int	parse_plane_transform(char **tokens, t_plane *plane,
			t_rt_error *error)
{
	t_transform	transform;

	if (parse_transformations(tokens, 4, &transform, error) != RT_ERR_OK)
		return (error->code);
	if (transform.has_translation)
		plane->point = ft_translation(plane->point, transform.translation);
	if (transform.has_rotation)
		plane->normal = ft_vnormalize(ft_rotate(plane->normal,
					transform.rotation));
	if (transform.has_material)
	{
		plane->material.specular = transform.material.specular;
		plane->material.diffuse = transform.material.diffuse;
		plane->material.shininess = transform.material.shininess;
		plane->material.reflective = transform.material.reflective;
		plane->material.transparency = transform.material.transparency;
		plane->material.ior = transform.material.ior;
	}
	return (RT_ERR_OK);
}

int	parse_plane(char **tokens, t_scene *scene, t_rt_error *error)
{
	t_plane	*plane;
	t_list	*node;

	if (validate_min_tokens(tokens, 4, error) != RT_ERR_OK)
		return (error->code);
	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (parse_plane_data(tokens, plane, error) != RT_ERR_OK)
		return (free(plane), error->code);
	init_plane_material(&plane->material);
	if (parse_color(tokens[3], &plane->material.color, error) != RT_ERR_OK)
		return (free(plane), error->code);
	if (parse_plane_transform(tokens, plane, error) != RT_ERR_OK)
		return (free(plane), error->code);
	node = ft_lstnew(plane);
	if (!node)
		return (free(plane), rt_error_set(error, RT_ERR_ALLOC));
	ft_lstadd_back(&scene->planes, node);
	return (RT_ERR_OK);
}
