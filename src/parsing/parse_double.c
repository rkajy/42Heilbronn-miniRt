/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:00:05 by radandri          #+#    #+#             */
/*   Updated: 2026/08/26 20:12:44 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_functions.h"
#include "utils.h"

int	parse_double(const char *s, double *result, t_rt_error *error)
{
	int	nb_comma;
	int	nb_alphabet;
	int	i;

	nb_comma = 0;
	nb_alphabet = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '.')
			nb_comma++;
		if (ft_isalpha(s[i]))
			nb_alphabet++;
	}
	if (nb_comma > 1 || nb_alphabet > 0)
		return (rt_error_set(error, RT_ERR_TRAILING_DATA),
			RT_ERR_TRAILING_DATA);
	*result = ft_atof(s);
	return (RT_ERR_OK);
}
