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
#include "parse_functions.h"

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

void	set_color_from_values(t_color *out, int values[3])
{
	out->r = values[0];
	out->g = values[1];
	out->b = values[2];
}

int	parse_color(const char *s, t_color *out, t_rt_error *e)
{
	char	**parts;
	int		index;
	int		values[3];

	if (s == NULL || out == NULL)
		return (rt_error_set(e, RT_ERR_INVALID_FORMAT), RT_ERR_INVALID_FORMAT);
	parts = ft_split(s, ',');
	if (parts == NULL)
		return (rt_error_set(e, RT_ERR_ALLOC), RT_ERR_ALLOC);
	index = -1;
	while (++index < 3 && parts[index] != NULL)
	{
		if (!is_digits_only(parts[index]))
			return (free_split(parts), rt_error_set(e, RT_ERR_INVALID_NUMBER),
				RT_ERR_INVALID_NUMBER);
		values[index] = ft_atoi(parts[index]);
		if (values[index] < 0 || values[index] > 255)
			return (free_split(parts), rt_error_set(e, RT_ERR_OUT_OF_RANGE),
				RT_ERR_OUT_OF_RANGE);
	}
	set_color_from_values(out, values);
	if (index != 3 || parts[index] != NULL)
		return (free_split(parts), rt_error_set(e, RT_ERR_TRAILING_DATA),
			RT_ERR_TRAILING_DATA);
	return (free_split(parts), RT_ERR_OK);
}
