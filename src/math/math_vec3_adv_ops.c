/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec3_adv_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:54:47 by asando            #+#    #+#             */
/*   Updated: 2026/08/14 16:56:43 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathrt.h"

t_vec3	ft_reflection(t_vec3 dir, t_vec3 normal)
{
	return ft_vsub(dir, ft_vscalar(normal, 2.0 * ft_vdot(dir, normal)));
}
