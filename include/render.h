/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:47:36 by asando            #+#    #+#             */
/*   Updated: 2026/08/14 17:03:37 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdio.h>
# include <stdlib.h>

# include "MLX42/MLX42.h"
# include "parse.h"
# include "mathrt.h"
# include "objects.h"

# define WIDTH 800
# define HEIGHT 600
# define REFLECT_DEPTH 3

typedef struct	s_mlx_interface
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_mlx_interface;

typedef enum	e_mlx_stat
{
	MLX_OK,
	MLX_ERR,
} t_mlx_stat;

t_mlx_stat	ft_init_mlx(t_mlx_interface *mi);
t_vec3		ft_trace(t_scene_rt *scene, t_ray ray, int depth);
t_vec3		ft_shade(t_scene_rt *scene, t_hit *hit, t_ray ray);
bool		ft_in_shadow(t_scene_rt *scene, t_vec3 point, t_light *light);
void		ft_render(t_mlx_interface *mlx_interface, t_scene_rt *scene);
void		ft_putpixel(mlx_image_t *img, uint32_t x, uint32_t y,
#endif
