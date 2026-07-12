/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:32:29 by asando            #+#    #+#             */
/*   Updated: 2026/07/12 21:27:44 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"
#include "../include/parse_functions.h"
#include "../include/utils.h"
#include "math_rt.h"
#include "parse.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_rt_error	error;
	t_scene		scene;
	t_scene_rt	scene_rt;

	if (!is_input_valid(argc, argv))
		return (printf("Error\n%s\n", RT_ERRMSG_USAGE), RT_ERR_USAGE);
	ft_bzero(&scene, sizeof(t_scene));
	if (parse_file(argv[1], &scene, &error) != RT_ERR_OK)
		return (destroy_scene(&scene), rt_error_print(&error), error.code);
	if (validate_scene(&scene, &error) != RT_ERR_OK)
		return (destroy_scene(&scene), rt_error_print(&error), error.code);
	if (DEBUG)
		debug_dump_scene(&scene);
	scene_rt_factory(&scene, &scene_rt);
	destroy_scene(&scene);
	return (0);
}
