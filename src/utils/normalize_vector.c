/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 20:20:00 by radandri          #+#    #+#             */
/*   Updated: 2026/07/09 00:33:23 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"
#include <math.h>

#define VECTOR_EPSILON 1e-12

static int	is_component_in_range(double value)
{
	return (value >= -1 && value <= 1);
}

int	normalize_vector(t_vec3 *vec, t_rt_error *error)
{
	double	length;

	if (!is_component_in_range(vec->x) || !is_component_in_range(vec->y)
		|| !is_component_in_range(vec->z))
		return (rt_error_set(error, RT_ERR_OUT_OF_RANGE));
	length = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	if (length < VECTOR_EPSILON)
		return (rt_error_set(error, RT_ERR_INVALID_VECTOR));
	vec->x = vec->x / length;
	vec->y = vec->y / length;
	vec->z = vec->z / length;
	return (RT_ERR_OK);
}
