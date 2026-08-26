/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:01:18 by radandri          #+#    #+#             */
/*   Updated: 2026/08/26 20:14:21 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_functions.h"
#include "libft.h"
#include "utils.h"

static int	parse_token(char **tokens, t_scene *scene, t_rt_error *error)
{
	if (ft_strncmp(tokens[0], "A", 2) == 0)
		return (parse_ambient((const char **)tokens, scene, error));
	if (ft_strncmp(tokens[0], "C", 2) == 0)
		return (parse_camera(tokens, scene, error));
	if (ft_strncmp(tokens[0], "L", 2) == 0)
		return (parse_light(tokens, scene, error));
	if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return (parse_sphere(tokens, scene, error));
	if (ft_strncmp(tokens[0], "pl", 3) == 0)
		return (parse_plane(tokens, scene, error));
	if (ft_strncmp(tokens[0], "cy", 3) == 0)
		return (parse_cylinder(tokens, scene, error));
	return (RT_ERR_UNKNOWN_IDENTIFIER);
}

int	parse_line(char *line, t_scene *scene, t_rt_error *error)
{
	char	**tokens;
	int		result;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (rt_error_set(error, RT_ERR_ALLOC));
	result = parse_token(tokens, scene, error);
	if (result == RT_ERR_UNKNOWN_IDENTIFIER)
		result = rt_error_set(error, RT_ERR_UNKNOWN_IDENTIFIER);
	if (result != RT_ERR_OK)
		return (free_split(tokens), result);
	free_split(tokens);
	return (RT_ERR_OK);
}
