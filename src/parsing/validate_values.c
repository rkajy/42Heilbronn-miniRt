/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 04:04:32 by radandri          #+#    #+#             */
/*   Updated: 2026/07/07 02:57:36 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include "../../include/parse.h"
#include <math.h>
#define EPSILON 1e-5

int	validate_ratio(double ratio, t_rt_error *error)
{
	if (!(ratio >= 0 && ratio <= 1))
	{
		return (rt_error_set(error, RT_ERR_OUT_OF_RANGE));
	}
	return (RT_ERR_OK);
}

int	validate_positive(double value, t_rt_error *error)
{
	if (!(value > 0))
	{
		return (rt_error_set(error, RT_ERR_OUT_OF_RANGE));
	}
	return (RT_ERR_OK);
}

int	validate_fov(double fov, t_rt_error *error)
{
	if (!(fov >= 0 && fov <= 180))
	{
		return (rt_error_set(error, RT_ERR_OUT_OF_RANGE));
	}
	return (RT_ERR_OK);
}

int	validate_normalized_vector(t_vec3 vec, t_rt_error *error)
{
	double	length;

	if (!(vec.x >= -1 && vec.x <= 1))
	{
		return (rt_error_set(error, RT_ERR_OUT_OF_RANGE));
	}
	if (!(vec.y >= -1 && vec.y <= 1))
	{
		return (rt_error_set(error, RT_ERR_OUT_OF_RANGE));
	}
	if (!(vec.z >= -1 && vec.z <= 1))
	{
		return (rt_error_set(error, RT_ERR_OUT_OF_RANGE));
	}
	length = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	if (fabs(length - 1.0) > EPSILON)
	{
		return (rt_error_set(error, RT_ERR_OUT_OF_RANGE));
	}
	return (RT_ERR_OK);
}

/*
 ** There's no restriction for position, it's always true expect alpha
 */
int	validate_coordinates(t_vec3 point, t_rt_error *error)
{
	(void)point;
	(void)error;
	return (RT_ERR_OK);
}
