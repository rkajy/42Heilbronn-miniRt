

#ifndef PARSE_FUNCTIONS_H
#define PARSE_FUNCTIONS_H

#include <stdbool.h>
#include "parse.h"

bool parse_int(char *s, int *out);
bool parse_double(char *s, double *out);
bool parse_color(char *s, t_color *out);
bool parse_vec3(char *s, t_vec3 *out);

bool parse_ambient(char *s, t_vec3 *out);
bool parse_camera(char **tokens, t_camera *camera);
bool parse_light(char **tokens, t_light *light);
bool parse_sphere(char **tokens, t_sphere *sphere);
bool parse_plane(char **tokens, t_plane *plane);
bool parse_cylinder(char **tokens, t_cylinder *cylinder);

/*
 ** eg: parse_line("sp 0,0,20 20 255,0,0", &scene)
 **
*/
bool parse_line(const char *line, t_scene *scene);

/*
 ** eg: parse_file("scene.rt", &scene);
 ** Parses the given .rt file and fills the scene structure with the parsed data.
 ** Returns true if parsing was successful, false otherwise.
 */
bool parse_file(const char *filename, t_scene *scene);

#endif