/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:22:53 by asando            #+#    #+#             */
/*   Updated: 2026/08/09 15:18:27 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_error_mlx(const char *msg)
{
	//TODO: printing error here and make clean all the memory allocation
}

int	ft_init_mlx(t_scene_rt *scene)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	scene->mlx = mlx_init(WIDTH, HEIGHT, "MiniRT", true);
	if (!scene->mlx)
	{
		ft_error_mlx("mlx_init failed");
		return (1);
	}
	scene->img = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
	if (!scene->img)
	{
		ft_error_mlx("mlx_new_image failed");
		return (1);
	}
	if (mlx_image_to_window(scene->mlx, scene->img, 0, 0) < 0)
	{
		ft_error_mlx("mlx_image_to_window failed");
		return (1);
	}
	return (0);
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

void	ft_render(t_scene_rt *scene)
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
			ft_put_pixel(scene->img, x, y, ft_to_rgb(color));
			x++;
		}
		y++;
	}
}
