/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 22:15:30 by radandri          #+#    #+#             */
/*   Updated: 2026/08/21 15:19:56 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse_functions.h"
#include "../../lib/libft/includes/libft.h"

static void	init_transform(t_transform *transform)
{
	transform->translation = ft_vec3(0, 0, 0);
	transform->rotation = ft_vec3(0, 0, 0);
	transform->has_translation = false;
	transform->has_rotation = false;
}

int	parse_transformations(char **tokens, int index, t_transform *transform,
		t_rt_error *error)
{
	init_transform(transform);
	while (tokens[index])
	{
		if (ft_strncmp(tokens[index], "T", 2) == 0
			&& !transform->has_translation && tokens[index + 1])
		{
			if (parse_vec3(tokens[index + 1], &transform->translation,
					error) != RT_ERR_OK)
				return (error->code);
			transform->has_translation = true;
			index += 2;
		}
		else if (ft_strncmp(tokens[index], "R", 2) == 0
			&& !transform->has_rotation && tokens[index + 1])
		{
			if (parse_vec3(tokens[index + 1], &transform->rotation,
					error) != RT_ERR_OK)
				return (error->code);
			transform->has_rotation = true;
			index += 2;
		}
		else
			return (rt_error_set(error, RT_ERR_TRAILING_DATA));
	}
	return (RT_ERR_OK);
}
