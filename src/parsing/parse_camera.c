/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:39:02 by radandri          #+#    #+#             */
/*   Updated: 2026/08/26 20:11:44 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_functions.h"
#include "libft.h"

static int	parse_camera_transform(char **tokens, t_camera *camera,
		t_rt_error *error)
{
	t_transform	transform;

	if (parse_transformations(tokens, 4, &transform, error) != RT_ERR_OK)
		return (error->code);
	if (transform.has_translation)
		camera->position = ft_translation(camera->position,
				transform.translation);
	if (transform.has_rotation)
		camera->orientation = ft_vnormalize(ft_rotate(camera->orientation,
					transform.rotation));
	return (RT_ERR_OK);
}

static int	parse_camera_data(char **tokens, t_camera *camera,
		t_rt_error *error)
{
	if (parse_vec3(tokens[1], &camera->position, error) != RT_ERR_OK)
		return (error->code);
	if (parse_vec3(tokens[2], &camera->orientation, error) != RT_ERR_OK)
		return (error->code);
	if (normalize_vector(&camera->orientation, error) != RT_ERR_OK)
		return (error->code);
	if (parse_double(tokens[3], &camera->fov, error) != RT_ERR_OK)
		return (error->code);
	if (validate_fov(camera->fov, error) != RT_ERR_OK)
		return (error->code);
	return (RT_ERR_OK);
}

int	parse_camera(char **tokens, t_scene *scene, t_rt_error *error)
{
	t_camera	*camera;
	t_list		*node;

	if (validate_min_tokens(tokens, 4, error) != RT_ERR_OK)
		return (error->code);
	if (ft_lstsize(scene->cameras) != 0)
		return (rt_error_set(error, RT_ERR_DUPLICATE_CAMERA));
	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (parse_camera_data(tokens, camera, error) != RT_ERR_OK)
		return (free(camera), error->code);
	if (parse_camera_transform(tokens, camera, error) != RT_ERR_OK)
		return (free(camera), error->code);
	node = ft_lstnew(camera);
	if (!node)
		return (free(camera), rt_error_set(error, RT_ERR_ALLOC));
	ft_lstadd_back(&scene->cameras, node);
	return (RT_ERR_OK);
}
