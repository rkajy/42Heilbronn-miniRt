/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 01:26:41 by radandri          #+#    #+#             */
/*   Updated: 2026/07/01 01:26:41 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FUNCTIONS_H
# define PARSE_FUNCTIONS_H

# include "parse.h"
# include <stdbool.h>

int	parse_int(char *s, int *out, t_rt_error *error);

/*
 ** eg: double d; parse_double("45.2", &d);
 */
int	parse_double(char *s, double *result, t_rt_error *error);

/*
 ** in: "255,0,128"
 ** out: {r=255, g=0, b=128}
 ** errors: 256,0,0 ; -1,0,0 ; 255,255 ; 255,255,255,255
 */
int	parse_color(const char *s, t_color *out, t_rt_error *error);

/*
 ** in: "1.5,-2.3,42"
 ** out: {x=1.5, y=-2.3, z=42}
 ** errors: 1,2 ; 1,2,3,4 ; 1,,3 ; a,b,c
 */
int	parse_vec3(char *s, t_vec3 *out, t_rt_error *error);

/*
 ** in: "A 0.2 255,255,255"
 ** out: {ratio= 0.2, {r=255, g=255, b=255}}
 ** errors: A; A 0.2; A 1.5 255,255,255(ratio > 1) ; A -0.1 255,255,255
 */
int	parse_ambient(char *s, t_ambient *ambient, t_rt_error *error);

/*
 ** in: "C -50,0,20 0,0,1 70"
 ** out: {position :{x=-50, y=0, z=20}; orientation:{x=0, y=0, z=1}; fov: 70}
 ** errors:
 ** C -50,0,20 0,0,1 190 (fov > 180) ;
 ** C -50,0,20 0,0,1 -10 (fov < 0) ;
 ** C -50,0,20 0,0,2 70 (orientation vector not normalized [-1;1]) ;
 ** C -50,0,20 0,0,1 (missing fov)
 */
int	parse_camera(char **tokens, t_camera *camera, t_rt_error *error);

/*
 ** in: "L -40,0,30 0.7 255,255,255"
 ** out: {position = {-40,0,30}; brightness= 0.7; color={255,255,255}}
 *** errors: L 0,0,0 1.5 255,255,255 (brightness > 1)
 */
int	parse_light(char **tokens, t_light *light, t_rt_error *error);

/*
 ** in: "sp 0,0,20 20 255,0,0"
 ** then split it to tokens like bellow
 ** tokens[0] = "sp";
 ** tokens[1] = "0,0,20";
 ** tokens[2] = "20";
 ** tokens[3] = "255,0,0";
 ** tokens[4] = NULL;
 ** then
 ** out: {center={0,0,20}; diameter=20; color={255,0,0}}
 ** errors:
 ** sp 0,0,20 -20 255,0,0 (diameter < 0) ;
 ** sp 0,0,20 20 256,0,0 (color > 255);
 ** diameter null
 */
int	parse_sphere(char **tokens, t_sphere *sphere, t_rt_error *error);

/*
 ** in: "pl 0,0,0 0,1,0 255,255,255"
 ** out: { point={0,0,0}; normal={0,1,0}; color={255,255,255}}
 ** errors:
 ** pl 0,0,0 0,2,0 255,255,255 (normal vector not normalized [-1;1]) ;
 ** pl 0,0,0 0,1,0 256,255,255 (color > 255) ;
 ** pl 0,0,0 0,1,0 (missing color)
 ** pl 0,0,0 0,0,0 255,255,255 (normal vector null)
 */
int	parse_plane(char **tokens, t_plane *plane, t_rt_error *error);

/*
 ** in: cy 50,0,20.6 0,0,1 14.2 21.42 10,0,255
 ** out:
 ** {
 **     center={50,0,20.6}; axis = {0,0,1};
 **     diameter=14.2; height=21.42; color={10,0,255}
 ** }
 */
int	parse_cylinder(char **tokens, t_cylinder *cylinder, t_rt_error *error);

/*
 ** eg: parse_line("sp 0,0,20 20 255,0,0", &scene)
 */
int	parse_line(const char *line, t_scene *scene, t_rt_error *error);

/*
 ** eg: parse_file("scene.rt", &scene);
 ** Parses the given .rt file and fills the scene structure with the parsed data.
 ** Returns true if parsing was successful, false otherwise.
 */
int	parse_file(const char *filename, t_scene *scene, t_rt_error *error);

#endif