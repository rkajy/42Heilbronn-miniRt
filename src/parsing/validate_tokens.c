/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 03:06:47 by radandri          #+#    #+#             */
/*   Updated: 2026/07/07 22:38:57 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include <stddef.h>

int	validate_tokens(char **tokens, int expected, t_rt_error *error)
{
	int	i;

	i = 0;
	while (tokens && tokens[i] != NULL)
	{
		i++;
	}
	if (i != expected)
	{
		return (rt_error_set(error, RT_ERR_TRAILING_DATA));
	}
	return (RT_ERR_OK);
}

int	validate_min_tokens(char **tokens, int minimum, t_rt_error *error)
{
	int	i;

	i = 0;
	while (tokens && tokens[i] != NULL)
		i++;
	if (i < minimum)
		return (rt_error_set(error, RT_ERR_TRAILING_DATA));
	return (RT_ERR_OK);
}
