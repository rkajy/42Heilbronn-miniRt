/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:09:42 by asando            #+#    #+#             */
/*   Updated: 2026/08/16 15:50:50 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_RT_H
# define MATH_RT_H

# include <math.h>

# include "parse.h"

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

t_vec3	ft_vec3(double x, double y, double z);
t_vec3	ft_vadd(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vsub(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vscalar(t_vec3 v1, double s);
double	ft_vdot(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vcross(t_vec3 v1, t_vec3 v2);
double	ft_vmagnitude(t_vec3 v);
t_vec3	ft_vnormalize(t_vec3 v);
t_vec3	ft_velement_mul(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vclamp(t_vec3 v, double min, double max);
t_vec3	ft_vneg(t_vec3 v);
t_vec3	ft_reflection(t_vec3 dir, t_vec3 normal);
t_ray	ft_ray(t_vec3 origin, t_vec3 direction);
t_ray	ft_ray_at(t_ray ray, double t);
#endif
