/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:17:07 by asando            #+#    #+#             */
/*   Updated: 2026/03/29 16:50:50 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "mathrt.h"
# include "parse.h"
# include <math.h>

typedef struct	s_hit
{
	double		t;
	t_vec3		point;
	t_vec3		normal;
	t_material	mat; //NOTE: Might not use it
}	t_hit;

typedef struct	s_constanta
{
	double	a;
	double	b;
	double	c;
	double	t;
}	t_constanta;

//TODO: in parsing make sure the structure for primitive shape compatible

#endif
