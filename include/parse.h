/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:48:50 by radandri          #+#    #+#             */
/*   Updated: 2026/05/03 17:01:12 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "../lib/libft/includes/libft.h"
#include "../lib/libft/includes/ft_printf.h"
#include "../lib/libft/includes/get_next_line_bonus.h"

typedef struct s_color
{
	double			r;
	double			g;
	double			b;
}				t_color;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
} t_ambiant;

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector, t_vec3;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	orientation;
	double	fov;
} t_camera;

typedef struct s_light
{
	t_vec3	pos;
	double	brightness;
	t_color	color;
} t_light;

typedef struct s_sphere
{
	t_vec3		center;
	double		diameter;
	t_color		color;
}				t_sphere;

typedef struct s_plane
{
	t_vec3	center;
	t_vec3	normal;
	t_color	color;
} t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	axis;
	double	diameter;
	double	height;
	t_color	color;
}t_cylinder;

typedef struct s_scene
{
	t_ambiant	ambient;
	t_camera	camera;
	t_light		light;
	t_list		*spheres;
	t_list		*planes;
	t_list		*cylinders;
}t_scene;

float			ft_atof(const char *str);

int				is_file_extension_valid(const char *filename,
					const char *extension);
int				is_input_valid(int argc, char **argv);
int				is_input_parsed(int argc, char **argv, void *data);

#endif
