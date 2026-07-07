/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 01:58:51 by radandri          #+#    #+#             */
/*   Updated: 2026/06/17 01:58:51 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse_functions.h"
#include "../../lib/libft/includes/libft.h"

int	parse_camera(char **tokens, t_scene *scene, t_rt_error *error)
{
	t_camera *camera;
	t_list *node;

	if (validate_tokens(tokens, 4, error) != RT_ERR_OK)
		return (error->code);
	if (ft_lstsize(scene->cameras) != 0)
		return (rt_error_set(error, RT_ERR_DUPLICATE_AMBIENT));
	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (rt_error_set(error, RT_ERR_ALLOC));
	if (parse_vec3(tokens[1], &camera->position, error) != RT_ERR_OK)
		return (free(camera), error->code);
	if (parse_vec3(tokens[2], &camera->orientation, error) != RT_ERR_OK)
		return (free(camera), error->code);
	if (validate_normalized_vector(camera->orientation, error) != RT_ERR_OK)
		return (free(camera), error->code);
	if (parse_double(tokens[3], &camera->fov, error) != RT_ERR_OK)
		return (free(camera), error->code);
	if (validate_fov(camera->fov, error) != RT_ERR_OK)
		return (error->code);
	node = ft_lstnew(camera);
	if (!node)
		return (free(camera), rt_error_set(error, RT_ERR_ALLOC));
	ft_lstadd_back(&scene->cameras, node);
	return (RT_ERR_OK);
}
