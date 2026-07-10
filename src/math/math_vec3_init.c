/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec3_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:29:16 by asando            #+#    #+#             */
/*   Updated: 2026/07/10 13:18:16 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"

#include "mathrt.h"

t_vec3	ft_vec3(double x, double y, double z)
{
	t_vec3	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}
