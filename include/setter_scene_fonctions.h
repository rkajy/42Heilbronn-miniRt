/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_scene_fonctions.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:02:28 by radandri          #+#    #+#             */
/*   Updated: 2026/06/17 02:02:28 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTER_SCENE_FONCTIONS_H
# define SETTER_SCENE_FONCTIONS_H

# include "parse.h"
# include <stdbool.h>

bool	scene_set_sphere(t_scene *scene, t_sphere *sphere);
bool	scene_set_plane(t_scene *scene, t_plane *plane);
bool	scene_set_cylinder(t_scene *scene, t_cylinder *cylinder);
bool	scene_set_camera(t_scene *scene, t_camera *camera);
bool	scene_set_light(t_scene *scene, t_light *light);
bool	scene_set_ambient(t_scene *scene, t_ambient *ambient);

#endif