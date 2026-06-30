/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:05:00 by radandri          #+#    #+#             */
/*   Updated: 2026/06/30 23:53:10 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include <stdio.h>

void	rt_error_init(t_rt_error *error)
{
	if (error == NULL)
		return ;
	error->code = RT_ERR_OK;
	error->message = NULL;
	error->line = -1;
}

void	rt_error_clear(t_rt_error *error)
{
	rt_error_init(error);
}

int	rt_error_set_at(t_rt_error *error, t_rt_error_code code, int line)
{
	if (error == NULL)
		return ((int)code);
	error->code = code;
	error->message = rt_error_message(code);
	error->line = line;
	return ((int)code);
}

int	rt_error_set(t_rt_error *error, t_rt_error_code code)
{
	return (rt_error_set_at(error, code, -1));
}

void	rt_error_print(const t_rt_error *error)
{
	if (error == NULL || error->message == NULL)
		return ;
	if (error->line > 0)
		fprintf(stderr, "Error\n%s (line %d)\n", error->message, error->line);
	else
		fprintf(stderr, "Error\n%s\n", error->message);
}
