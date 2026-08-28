/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:01:45 by radandri          #+#    #+#             */
/*   Updated: 2026/08/28 14:44:13 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parse.h"
#include "parse_functions.h"

/*
** A sphere only needs its center translated; its radius is unchanged.
** Example: "sp 0,0,0 2 255,0,0 T 1,0,0" moves the center on X.
*/
static int	parse_sphere_transform(char **tokens, t_sphere *sphere,
			t_rt_error *error)
{
	t_transform	transform;

	if (parse_transformations(tokens, 4, &transform, error) != RT_ERR_OK)
		return (error->code);
	if (transform.has_translation)
		sphere->center = ft_translation(sphere->center, transform.translation);
	if (transform.has_material)
	{
		sphere->material.specular = transform.material.specular;
		sphere->material.diffuse = transform.material.diffuse;
		sphere->material.shininess = transform.material.shininess;
		sphere->material.reflective = transform.material.reflective;
		sphere->material.transparency = transform.material.transparency;
		sphere->material.ior = transform.material.ior;
	}
	return (RT_ERR_OK);
}

/*
** The scene format stores a sphere size as a positive diameter.
** Example: a value of "2" creates a sphere with radius 1.
*/
static int	parse_sphere_data(char **tokens, t_sphere *sphere,
			t_rt_error *error)
{
	if (parse_vec3(tokens[1], &sphere->center, error) != RT_ERR_OK)
		return (error->code);
	if (parse_double(tokens[2], &sphere->diameter, error) != RT_ERR_OK)
		return (error->code);
	if (validate_positive(sphere->diameter, error) != RT_ERR_OK)
		return (error->code);
	return (RT_ERR_OK);
}

static void	init_sphere_material(t_material *material)
{
	material->specular = 0.5;
	material->diffuse = 1;
	material->shininess = 32;
	material->reflective = 0;
	material->transparency = 0.0;
	material->ior = 1.5;
}

int	parse_sphere(char **tokens, t_scene *scene, t_rt_error *error)
{
	t_sphere	*sphere;
	t_list		*node;

	if (validate_min_tokens(tokens, 4, error) != RT_ERR_OK)
		return (error->code);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (parse_sphere_data(tokens, sphere, error) != RT_ERR_OK)
		return (free(sphere), error->code);
	init_sphere_material(&sphere->material);
	if (parse_color(tokens[3], &sphere->material.color, error) != RT_ERR_OK)
		return (free(sphere), error->code);
	if (parse_sphere_transform(tokens, sphere, error) != RT_ERR_OK)
		return (free(sphere), error->code);
	node = ft_lstnew(sphere);
	if (!node)
		return (free(sphere), rt_error_set(error, RT_ERR_ALLOC));
	ft_lstadd_back(&scene->spheres, node);
	return (RT_ERR_OK);
}
