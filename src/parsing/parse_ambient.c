/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 01:58:22 by radandri          #+#    #+#             */
/*   Updated: 2026/06/17 01:58:22 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include "../../include/parse.h"
#include "../../include/parse_functions.h"
#include "../../include/utils.h"

int	parse_ambient(const char **tokens, t_scene *scene, t_rt_error *error)
{
	t_ambient	*ambient;
	t_list		*node;

	if (validate_tokens((char **)tokens, 3, error) != RT_ERR_OK)
		return (error->code);
	if (ft_lstsize(scene->ambients) != 0)
		return (rt_error_set(error, RT_ERR_DUPLICATE_AMBIENT));
	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (parse_double(tokens[1], &ambient->ratio, error) != RT_ERR_OK)
		return (free(ambient), error->code);
	if (parse_color(tokens[2], &ambient->color, error) != RT_ERR_OK)
		return (free(ambient), error->code);
	node = ft_lstnew(ambient);
	if (!node)
		return (free(ambient), rt_error_set(error, RT_ERR_ALLOC));
	ft_lstadd_back(&scene->ambients, node);
	if (validate_ratio(ambient->ratio, error) != RT_ERR_OK)
		return (error->code);
	return (RT_ERR_OK);
}
