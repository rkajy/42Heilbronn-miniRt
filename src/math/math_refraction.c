/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_refraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 22:25:53 by asando            #+#    #+#             */
/*   Updated: 2026/08/28 12:59:16 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "math_rt.h"

static double	ft_clamp_scalar(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

static double	ft_eta_calc(double ior, int num)
{
	double	etai;
	double	etat;
	double	temp;

	etai = 1.0;
	etat = ior;
	if (num == 1)
	{
		temp = etai;
		etai = etat;
		etat = temp;
	}
	return (etai / etat);
}

t_vec3	ft_refract(t_vec3 ray, t_vec3 normal, double ior)
{
	double	cosi;
	double	eta;
	double	k;

	cosi = ft_clamp_scalar(ft_vdot(ray, normal), -1.0, 1.0);
	if (cosi < 0.0)
	{
		cosi = -cosi;
		eta = ft_eta_calc(ior, 2);
	}
	else
	{
		eta = ft_eta_calc(ior, 1);
		normal = ft_vneg(normal);
	}
	k = 1.0 - eta * eta * (1.0 - cosi * cosi);
	if (k < 0.0)
		return (ft_vec3(0, 0, 0));
	return (ft_vnormalize(
			ft_vadd(
				ft_vscalar(ray, eta),
				ft_vscalar(normal, eta * cosi - sqrt(k)))));
}

double	ft_fresnel_schlick(double cosi, double ior)
{
	double	r0;

	r0 = (1.0 - ior) / (1.0 + ior);
	r0 = r0 * r0;
	return (r0 + (1.0 - r0) * pow(1.0 - cosi, 5.0));
}
