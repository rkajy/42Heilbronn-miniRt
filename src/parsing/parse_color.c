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

static int	parse_color_value(const char *part, int *value, t_rt_error *e)
{
	if (!is_digits_only(part))
		return (rt_error_set(e, RT_ERR_INVALID_NUMBER));
	*value = ft_atoi(part);
	if (*value < 0 || *value > 255)
		return (rt_error_set(e, RT_ERR_OUT_OF_RANGE));
	return (RT_ERR_OK);
}

static int	set_color_from_values(t_color *out, int values[3])
{
	out->r = values[0];
	out->g = values[1];
	out->b = values[2];
	return (RT_ERR_OK);
}

int	parse_color(const char *s, t_color *out, t_rt_error *e)
{
	char	**parts;
	int		values[3];

	if (s == NULL || out == NULL)
		return (rt_error_set(e, RT_ERR_INVALID_FORMAT));
	parts = ft_split(s, ',');
	if (parts == NULL)
		return (rt_error_set(e, RT_ERR_ALLOC));
	if (parts[0] == NULL || parts[1] == NULL || parts[2] == NULL
		|| parts[3] != NULL)
		return (free_split(parts), rt_error_set(e, RT_ERR_TRAILING_DATA));
	if (parse_color_value(parts[0], &values[0], e) != RT_ERR_OK)
		return (free_split(parts), e->code);
	if (parse_color_value(parts[1], &values[1], e) != RT_ERR_OK)
		return (free_split(parts), e->code);
	if (parse_color_value(parts[2], &values[2], e) != RT_ERR_OK)
		return (free_split(parts), e->code);
	if (set_color_from_values(out, values) != RT_ERR_OK)
		return (free_split(parts), rt_error_set(e, RT_ERR_ALLOC));
	return (free_split(parts), RT_ERR_OK);
}
