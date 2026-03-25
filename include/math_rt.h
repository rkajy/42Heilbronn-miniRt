/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:09:42 by asando            #+#    #+#             */
/*   Updated: 2026/03/25 21:17:31 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHRT_H
# define MATHRT_H

# include <math.h>

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct	s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;


t_vec3	ft_vec3(double x, double y, double z);
t_vec3	ft_vadd(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vsub(t_vec3 v1, t_vec3 v2);
t_vec3	ft_scalar_mul(t_vec3 v1, double s);
double	ft_dot_mul(t_vec3 v1, t_vec3 v2);
t_vec3	ft_cross_mul(t_vec3 v1, t_vec3 v2);
double	ft_vmagnitude(t_vec3 v);
t_vec3	ft_vnormalize(t_vec3 v);
t_vec3	ft_element_vmul(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vclamp(t_vec3 v, double min, double max);
t_ray	ft_ray(t_vec3 origin, t_vec3 direction);
t_ray	ft_ray_at(t_ray ray, double t);
#endif
