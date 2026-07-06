/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:01:45 by radandri          #+#    #+#             */
/*   Updated: 2026/06/17 02:01:45 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse_functions.h"

int	parse_sphere(char **tokens, t_scene *scene, t_rt_error *error)
{
	(void)tokens;
	(void)scene;
	rt_error_set(error, RT_ERR_INVALID_FORMAT);
	return (RT_ERR_INVALID_FORMAT);
}
