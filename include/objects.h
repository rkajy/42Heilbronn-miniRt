/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:17:07 by asando            #+#    #+#             */
/*   Updated: 2026/08/16 12:29:48 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include <math.h>
# include <stdbool.h>

# include "mathrt.h"
# include "parse.h"

typedef struct	s_hit
{
	double		t;
	t_vec3		point;
	t_vec3		normal;
	t_material	mat;
}	t_hit;

typedef struct	s_constanta
{
	double	a;
	double	b;
	double	c;
	double	t;
}	t_constanta;

typedef enum	e_caps
{
	C_TOP,
	C_BOTTOM,
}	t_caps;

bool	ft_hit_plane(t_ray ray, t_plane *pl, t_hit *hit);
bool	ft_hit_sphere(t_ray ray, t_sphere *sp, t_hit *hit);
bool	ft_hit_cap(t_ray ray, t_cylinder *cy, t_hit *hit, t_caps cap);
bool	ft_hit_cylinder(t_ray ray, t_cylinder *cy, t_hit *hit);

#endif
