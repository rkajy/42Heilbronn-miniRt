/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:00:58 by radandri          #+#    #+#             */
/*   Updated: 2026/07/09 00:42:09 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include "../../include/parse.h"
#include "../../include/parse_functions.h"
#include "../../include/math_rt.h"

int	parse_light(char **tokens, t_scene *scene, t_rt_error *error)
{
	t_light	*light;
	t_list	*node;
	t_transform	transform;

	if (validate_min_tokens(tokens, 4, error) != RT_ERR_OK)
		return (error->code);
	light = malloc(sizeof(t_light));
	if (!light)
		return (rt_error_set(error, RT_ERR_ALLOC));
	light->intensity = 1.0;
	if (parse_vec3(tokens[1], &light->position, error) != RT_ERR_OK)
		return (free(light), error->code);
	if (parse_double(tokens[2], &light->brightness, error) != RT_ERR_OK)
		return (free(light), error->code);
	if (parse_color(tokens[3], &light->light_color, error) != RT_ERR_OK)
		return (free(light), error->code);
	if (validate_ratio(light->brightness, error) != RT_ERR_OK)
		return (free(light), error->code);
	if (validate_ratio(light->intensity, error) != RT_ERR_OK)
		return (free(light), error->code);
	if (parse_transformations(tokens, 4, &transform, error) != RT_ERR_OK)
		return (free(light), error->code);
	if (transform.has_translation)
		light->position = ft_translation(light->position,
			transform.translation);
	node = ft_lstnew(light);
	if (!node)
		return (free(light), rt_error_set(error, RT_ERR_ALLOC));
	return (ft_lstadd_back(&scene->lights, node), RT_ERR_OK);
}
