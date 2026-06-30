/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:00:05 by radandri          #+#    #+#             */
/*   Updated: 2026/06/17 02:00:05 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse_functions.h"

int	parse_double(char *s, double *result, t_rt_error *error)
{
	(void)s;
	(void)result;
	rt_error_set(error, RT_ERR_INVALID_FORMAT);
	return (RT_ERR_INVALID_FORMAT);
}
