/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:01:18 by radandri          #+#    #+#             */
/*   Updated: 2026/06/17 02:01:18 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse_functions.h"
#include "../../lib/libft/includes/libft.h"
#include "../../include/utils.h"

int	parse_line(char *line, t_scene *scene, t_rt_error *error)
{
	char **tokens;
	int	result;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (ft_strncmp(tokens[0], "A", 2) == 0)
	{

		result = parse_ambient((const char **)tokens, scene, error);
		return (free_split(tokens), result);
	}
	if (ft_strncmp(tokens[0], "C", 2) == 0)
	{	
		result = parse_camera(tokens, scene, error);
		return (free_split(tokens), result);
	}
	if (ft_strncmp(tokens[0], "L", 2) == 0)
	{
		result = parse_light(tokens, scene, error);
		return (free_split(tokens), result);
	}
	if (ft_strncmp(tokens[0], "sp", 3) == 0)
	{
		result = parse_sphere(tokens, scene, error);
		return (free_split(tokens), result);
	}
	if (ft_strncmp(tokens[0], "pl", 3) == 0)
	{
		result = parse_plane(tokens, scene, error);
		return (free_split(tokens), result);
	}
	if (ft_strncmp(tokens[0], "cy", 3) == 0)
	{
		result = parse_cylinder(tokens, scene, error);
		return (free_split(tokens), result);
	}
	free_split(tokens);
	return (rt_error_set(error, RT_ERR_UNKNOWN_IDENTIFIER));
}
