/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec3_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:34:04 by asando            #+#    #+#             */
/*   Updated: 2026/03/25 11:58:38 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathrt.h"

double	ft_vmagnitude(t_vec3 v)
{
	double	res;
	double	dot_product;

	dot_product = ft_dot_mul(v, v);
	res = sqrt(dot_product;
	return (res);
}

t_vec3	ft_vnormalize(t_vec3 v)
{
	double	v_magnitude;
	t_vec3	res;

	v_magnitude = ft_vmagnitude(v);
	if (v_magnitude == 0)
		res = ft_vec3(0, 0, 0);
	else
		res = ft_scalar_mul(v, 1.0/v_magnitude);
	return (res);
}
