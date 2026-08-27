/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:32:29 by asando            #+#    #+#             */
/*   Updated: 2026/08/27 18:16:37 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "error.h"
#include "parse.h"
#include "parse_functions.h"
#include "render.h"
#include "utils.h"
#include <stdio.h>

static int	ft_draw(t_mlx_interface *mi, t_scene_rt *scene_rt)
{
	if (ft_init_mlx(mi) != MLX_OK)
		return (1);
	ft_render(mi, scene_rt);
	if (ft_mlx_image_window(mi) != MLX_OK)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rt_error		error;
	t_scene			scene;
	t_scene_rt		scene_rt;
	t_mlx_interface	mlx_interface;

	if (!is_input_valid(argc, argv))
		return (printf("Error\n%s\n", RT_ERRMSG_USAGE), RT_ERR_USAGE);
	ft_bzero(&scene, sizeof(t_scene));
	ft_bzero(&mlx_interface, sizeof(t_mlx_interface));
	if (parse_file(argv[1], &scene, &error) != RT_ERR_OK)
		return (destroy_scene(&scene), rt_error_print(&error), error.code);
	if (validate_scene(&scene, &error) != RT_ERR_OK)
		return (destroy_scene(&scene), rt_error_print(&error), error.code);
	// if (DEBUG)
	//	debug_dump_scene(&scene);
	scene_rt_factory(&scene, &scene_rt);
	destroy_scene(&scene);
	if (ft_draw(&mlx_interface, &scene_rt) == 0)
	{
		mlx_key_hook(mlx_interface.mlx, ft_key_hook, &mlx_interface);
		mlx_loop(mlx_interface.mlx);
	}
	if (mlx_interface.mlx)
		mlx_terminate(mlx_interface.mlx);
	return (0);
}
