/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:18:33 by radandri          #+#    #+#             */
/*   Updated: 2026/08/16 16:00:45 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../lib/libft/includes/ft_printf.h"
# include "../lib/libft/includes/get_next_line_bonus.h"
# include "../lib/libft/includes/libft.h"
# include "error.h"
# include <stdbool.h>

/*
** r: red
** g: green
** b: blue
*/
typedef struct s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef struct s_material
{
	t_color		color;
	//TODO: double	specular; default = 0.5 value range = 0.0 - 1.0
	//TODO: double	diffuse; default = 1.0 value range = 0.0 - 1.0
	//TODO: double	shininess; default = 32 value range = 8 - 128
	//TODO: double	reflective; default = 0.0 value range = 0.0 - 1.0
}				t_material;

typedef struct s_ambient
{
	double		ratio;
	t_material	material;
}				t_ambient;

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
} t_vector,	t_vec3;

/*
 ** orientation is a normalized vector
 */
typedef struct s_camera
{
	t_vec3		orientation;
	t_vec3		position;
	//TODO: t_vec3		right;
	//TODO: t_vec3		up;
	//TODO: double		vp_width;
	//TODO: double		vp_height;
	double		fov;
}				t_camera;

typedef struct s_light
{
	t_vec3		position;
	double		brightness;
	//TODO: double intensity; default 1.0 value range = 0.0 - 1.0
	//TODO: delete t_material from this struct we dont need material characteristic on light
	//TODO: t_color	light_color;
	t_material	material;
}				t_light;

typedef struct s_sphere
{
	t_vec3		center;
	double		diameter;
	t_material	material;
}				t_sphere;

typedef struct s_plane
{
	t_vec3		point;
	t_vec3		normal;
	t_material	material;
}				t_plane;

typedef struct s_cylinder
{
	t_vec3		center;
	t_vec3		axis;
	double		diameter;
	double		height;
	t_material	material;
}				t_cylinder;

typedef struct s_scene
{
	t_list		*ambients;
	t_list		*cameras;
	t_list		*lights;
	t_list		*spheres;
	t_list		*planes;
	t_list		*cylinders;
}				t_scene;

# define MAX_SPHERES 1024
# define MAX_PLANES 1024
# define MAX_CYLINDERS 1024

//TODO: try to support multiple light source
//TODO: do len lights
typedef struct s_scene_rt
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	//TODO: t_light		lights[MAX_LIGHTS];
	//TODO: size_t		nb_lights; default = 1
	t_sphere	spheres[MAX_SPHERES];
	size_t		nb_spheres;
	t_plane		planes[MAX_PLANES];
	size_t		nb_planes;
	t_cylinder	cylinders[MAX_CYLINDERS];
	size_t		nb_cylinders;
}				t_scene_rt;

int				validate_tokens(char **tokens, int expected, t_rt_error *error);
int				validate_ratio(double ratio, t_rt_error *error);
int				validate_positive(double value, t_rt_error *error);
int				validate_fov(double fov, t_rt_error *error);
int				validate_normalized_vector(t_vec3 vec, t_rt_error *error);
int				validate_coordinates(t_vec3 point, t_rt_error *error);
int				normalize_vector(t_vec3 *vec, t_rt_error *error);
void			debug_dump_scene(const t_scene *scene);
void			debug_dump_spheres(t_list *node);
void			debug_dump_planes(t_list *node);
void			debug_dump_cylinders(t_list *node);
void			destroy_scene(t_scene *scene);
bool			scene_rt_factory(const t_scene *src, t_scene_rt *dst);
#endif
