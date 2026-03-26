/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:17:07 by asando            #+#    #+#             */
/*   Updated: 2026/03/26 21:22:20 by asando           ###   ########.fr       */
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

#endif
