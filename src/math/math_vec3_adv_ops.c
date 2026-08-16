/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec3_adv_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:54:47 by asando            #+#    #+#             */
/*   Updated: 2026/08/16 12:28:49 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathrt.h"

t_vec3	ft_reflection(t_vec3 ray_dir, t_vec3 v_normal)
{
	t_vec3	res;

	res = ft_vsub(ray_dir,
			ft_vscalar(v_normal, 2.0 * ft_vdot(ray_dir, v_normal)));
	return (res);
}
