/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 02:51:18 by radandri          #+#    #+#             */
/*   Updated: 2026/06/30 02:51:18 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse_functions.h"
#include "../../include/utils.h"

static bool	is_digits_only(const char *s)
{
	int	index;

	if (s == NULL || *s == '\0')
		return (false);
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] < '0' || s[index] > '9')
			return (false);
		index++;
	}
	return (true);
}

bool	parse_color(const char *s, t_color *out)
{
	char	**parts;
	int		index;
	int		values[3];

	if (s == NULL || out == NULL)
		return (false);
	parts = ft_split(s, ',');
	if (parts == NULL)
		return (false);
	index = 0;
	while (index < 3 && parts[index] != NULL)
	{
		if (!is_digits_only(parts[index]))
			return (free_split(parts), false);
		values[index] = ft_atoi(parts[index]);
		if (values[index] < 0 || values[index] > 255)
			return (free_split(parts), false);
		index++;
	}
	out->r = values[0];
	out->g = values[1];
	out->b = values[2];
	if (index != 3 || parts[index] != NULL)
		return (free_split(parts), false);
	return (free_split(parts), true);
}
