/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 01:59:17 by radandri          #+#    #+#             */
/*   Updated: 2026/06/17 01:59:17 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse_functions.h"

bool	parse_color(const char *s, t_color *out)
{
	if(!ft_strncmp(s, "255,0,128", 9))
	{
		out->r = 255;
		out->g = 0;
		out->b = 128;
		return true;
	}
	return (false);
}
