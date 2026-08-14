/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:22:53 by asando            #+#    #+#             */
/*   Updated: 2026/08/14 15:43:54 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

//TODO: error handling togather with error from parsing
static void	ft_error_mlx(const char *msg)
{
	printf("Error");
}

//NOTE: idk when to clean scene if mlx throw some error
//NOTE: option 1 : on the main
//NOTE: option 2 on ft_init_mlx
t_mlx_stat	ft_init_mlx(t_mlx_interface *mlx_interface)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_interface->mlx = mlx_init(WIDTH, HEIGHT, "MiniRT", true);
	if (!mlx_interface->mlx)
	{
		ft_error_mlx("mlx_init failed");
		return (MLX_ERR);
	}
	mlx_interface->img = mlx_new_image(mlx_interface->mlx, WIDTH, HEIGHT);
	if (!mlx_interface->img)
	{
		ft_error_mlx("mlx_new_image failed");
		mlx_terminate(mlx_interface->mlx);
		return (MLX_ERR);
	}
	return (MLX_OK);
}

void	ft_putpixel(mlx_image_t *img, uint32_t x, uint32_t y,
						uint32_t color)
{
	uint32_t	pixel_index;

	pixel_index = 0;
	if (x >= img->width || y >= img->height)
		return ;
	pixel_index = (y * img->width + x) * 4;
	img->pixels[pixel_index + 0] = (color >> 24) & 0xFF;
	img->pixels[pixel_index + 1] = (color >> 16) & 0XFF;
	img->pixels[pixel_index + 2] = (color >> 8) & 0XFF;
	img->pixels[pixel_index + 3] = (color >> 0) & 0XFF;
	return ;
}

uint32_t ft_to_rgb(t_vec3 color)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = (uint32_t)(color.x * 255.0);
	g = (uint32_t)(color.y * 255.0);
	b = (uint32_t)(color.z * 255.0);

	return (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

void	ft_render(t_mlx_interface *mlx_interface, t_scene_rt *scene)
{
	uint32_t	x;
	uint32_t	y;
	t_ray		ray;
	t_hit		hit;
	t_vec3		color;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			ray = ft_generate_ray(scene, x, y);
			color = ft_trace(scene, ray, &hit);
			ft_put_pixel(mlx_interface->img, x, y, ft_to_rgb(color));
			x++;
		}
		y++;
	}
}
