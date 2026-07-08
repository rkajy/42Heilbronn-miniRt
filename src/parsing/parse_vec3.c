/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:04:44 by radandri          #+#    #+#             */
/*   Updated: 2026/07/09 00:47:50 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include "../../include/parse_functions.h"
#include "../../include/utils.h"
#include "../../lib/libft/includes/libft.h"

int	parse_vec3(const char *s, t_vec3 *out, t_rt_error *error)
{
	char	**tokens;

	tokens = ft_split(s, ',');
	if (!tokens)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (validate_tokens(tokens, 3, error) != RT_ERR_OK)
		return (free_split(tokens), error->code);
	if (parse_double(tokens[0], &out->x, error) != RT_ERR_OK)
		return (free_split(tokens), error->code);
	if (parse_double(tokens[1], &out->y, error) != RT_ERR_OK)
		return (free_split(tokens), error->code);
	if (parse_double(tokens[2], &out->z, error) != RT_ERR_OK)
		return (free_split(tokens), error->code);
	return (free_split(tokens), RT_ERR_OK);
}
