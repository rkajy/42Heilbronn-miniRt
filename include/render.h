/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:47:36 by asando            #+#    #+#             */
/*   Updated: 2026/08/14 15:21:10 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "MLX42/MLX42.h"
# include "parse.h"
# include <stdio.h>
# include <stdlib.h>

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
#endif
