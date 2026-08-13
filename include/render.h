/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:47:36 by asando            #+#    #+#             */
/*   Updated: 2026/08/13 21:37:59 by asando           ###   ########.fr       */
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

int	ft_init_mlx(t_scene_rt *scene);
#endif
