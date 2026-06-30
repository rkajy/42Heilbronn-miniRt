/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:00:43 by radandri          #+#    #+#             */
/*   Updated: 2026/06/17 02:00:43 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse_functions.h"

int	parse_int(char *s, int *out, t_rt_error *error)
{
	(void)s;
	(void)out;
	rt_error_set(error, RT_ERR_INVALID_FORMAT);
	return (RT_ERR_INVALID_FORMAT);
}
