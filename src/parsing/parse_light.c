/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:00:58 by radandri          #+#    #+#             */
/*   Updated: 2026/08/26 20:13:55 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parse.h"
#include "parse_functions.h"
#include "math_rt.h"

static int	parse_light_data(char **tokens, t_light *light, t_rt_error *error)
{
	light->intensity = 1.0;
	if (parse_vec3(tokens[1], &light->position, error) != RT_ERR_OK)
		return (error->code);
	if (parse_double(tokens[2], &light->intensity, error) != RT_ERR_OK)
		return (error->code);
	if (parse_color(tokens[3], &light->light_color, error) != RT_ERR_OK)
		return (error->code);
	if (validate_ratio(light->intensity, error) != RT_ERR_OK)
		return (error->code);
	if (validate_ratio(light->intensity, error) != RT_ERR_OK)
		return (error->code);
	return (RT_ERR_OK);
}

static int	parse_light_transform(char **tokens, t_light *light,
		t_rt_error *error)
{
	t_transform	transform;

	if (parse_transformations(tokens, 4, &transform, error) != RT_ERR_OK)
		return (error->code);
	if (transform.has_translation)
		light->position = ft_translation(light->position,
				transform.translation);
	return (RT_ERR_OK);
}

int	parse_light(char **tokens, t_scene *scene, t_rt_error *error)
{
	t_light	*light;
	t_list	*node;

	if (validate_min_tokens(tokens, 4, error) != RT_ERR_OK)
		return (error->code);
	light = malloc(sizeof(t_light));
	if (!light)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (parse_light_data(tokens, light, error) != RT_ERR_OK)
		return (free(light), error->code);
	if (parse_light_transform(tokens, light, error) != RT_ERR_OK)
		return (free(light), error->code);
	node = ft_lstnew(light);
	if (!node)
		return (free(light), rt_error_set(error, RT_ERR_ALLOC));
	return (ft_lstadd_back(&scene->lights, node), RT_ERR_OK);
}
