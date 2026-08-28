/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:05:40 by radandri          #+#    #+#             */
/*   Updated: 2026/08/28 14:39:41 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_functions.h"
#include "utils.h"

static int	parse_material_values(char **values, t_material *material,
		t_rt_error *error)
{
	if (!values[0] || !values[1] || !values[2] || !values[3] || !values[4]
		|| !values[5])
		return (rt_error_set(error, RT_ERR_TRAILING_DATA));
	if (parse_double(values[0], &material->specular, error) != RT_ERR_OK
		|| validate_ratio(material->specular, error) != RT_ERR_OK)
		return (error->code);
	if (parse_double(values[1], &material->diffuse, error) != RT_ERR_OK
		|| validate_ratio(material->diffuse, error) != RT_ERR_OK)
		return (error->code);
	if (parse_double(values[2], &material->shininess, error) != RT_ERR_OK)
		return (error->code);
	if (material->shininess < 1 || material->shininess > 1000)
		return (rt_error_set(error, RT_ERR_OUT_OF_RANGE));
	if (parse_double(values[3], &material->reflective, error) != RT_ERR_OK
		|| validate_ratio(material->reflective, error) != RT_ERR_OK)
		return (error->code);
	if (parse_double(values[4], &material->transparency, error) != RT_ERR_OK
		|| validate_ratio(material->transparency, error) != RT_ERR_OK)
		return (error->code);
	if (material->ior < 1.0 || material->ior > 3.0)
		return (rt_error_set(error, RT_ERR_OUT_OF_RANGE));
	return (RT_ERR_OK);
}

int	parse_material(const char *s, t_material *material, t_rt_error *error)
{
	char	**values;

	values = ft_split(s, ',');
	if (!values)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (parse_material_values(values, material, error) != RT_ERR_OK)
		return (free_split(values), error->code);
	return (free_split(values), RT_ERR_OK);
}
