/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:32:29 by asando            #+#    #+#             */
/*   Updated: 2026/08/15 21:52:05 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "MLX42/MLX42.h"
#include "../include/error.h"
#include "../include/parse_functions.h"
#include "../include/utils.h"
#include "mathrt.h"
#include "parse.h"
#include "render.h"

int	main(int argc, char **argv)
{
	t_rt_error		error;
	t_scene			scene;
	t_scene_rt		scene_rt;
	t_mlx_interface	mlx_interface;

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
	if (ft_init_mlx(&mlx_interface) != MLX_OK)
	{
		//NOTE: Not sure
		printf("Error");
	}
	ft_render(&mlx_interface, &scene_rt);
	if (mlx_image_to_window(mlx_interface.mlx, mlx_interface.img, 0, 0) < 0)
	{
		ft_error_mlx("mlx_image_to_window failed");
		mlx_delete_image(mlx_interface.mlx, mlx_interface.img);
		mlx_terminate(mlx_interface.mlx);
		return (1);
	}
	mlx_key_hook(mlx_interface.mlx, ft_key_hook, &mlx_interface);
	mlx_loop(mlx_interface.mlx);
	mlx_terminate(mlx_interface.mlx);
	//TODO: should we scene_rt also destroy?
	destroy_scene(&scene);
	return (0);
}
