/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:32:29 by asando            #+#    #+#             */
/*   Updated: 2026/08/21 20:37:44 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "MLX42/MLX42.h"
#include "../include/error.h"
#include "../include/parse_functions.h"
#include "../include/utils.h"
#include "../include/math_rt.h"
#include "parse.h"
#include "render.h"

int	ft_draw(t_mlx_interface *mi, t_scene_rt *scene_rt)
{
	if (ft_init_mlx(mi) != MLX_OK)
	{
		//TODO: destroy scene_rt?
		return (1);
	}
	ft_render(mi, scene_rt);
	if (ft_mlx_image_window(mi) != MLX_OK)
	{
		//TODO: destroy scene_rt?
		return (1);
	}
	return (0);
}

//TODO: main should be more tidy, all parsing should be groupped
//TODO: if everything ok after termination destroy scene_rt
int	main(int argc, char **argv)
{
	t_rt_error		error;
	t_scene			scene;
	t_scene_rt		scene_rt;
	// t_mlx_interface	mlx_interface;

	//TODO: FROM HERE
	if (!is_input_valid(argc, argv))
		return (printf("Error\n%s\n", RT_ERRMSG_USAGE), RT_ERR_USAGE);
	ft_bzero(&scene, sizeof(t_scene));
	if (parse_file(argv[1], &scene, &error) != RT_ERR_OK)
		return (destroy_scene(&scene), rt_error_print(&error), error.code);
	if (validate_scene(&scene, &error) != RT_ERR_OK)
		return (destroy_scene(&scene), rt_error_print(&error), error.code);
	if (DEBUG)
		debug_dump_scene(&scene);
	//TODO: TO HERE could be grupped in one helper static function
	scene_rt_factory(&scene, &scene_rt);
	destroy_scene(&scene);
	// if (ft_draw(&mlx_interface, &scene_rt) != 0)
	// {
	// 	mlx_key_hook(mlx_interface.mlx, ft_key_hook, &mlx_interface);
	// 	mlx_loop(mlx_interface.mlx);
	// }
	// mlx_terminate(mlx_interface.mlx);
	return (0);
}
