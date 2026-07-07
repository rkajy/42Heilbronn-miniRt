/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:00:22 by radandri          #+#    #+#             */
/*   Updated: 2026/06/17 02:00:22 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include "../../include/parse_functions.h"
#include "../../include/utils.h"
#include <fcntl.h>

int	parse_file(const char *filename, t_scene *scene, t_rt_error *error)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (rt_error_set(error, RT_ERR_FILE_OPEN));
	error->line = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_comment_or_empty(line))
		{
			error->line++;
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		line = clean_line(line);
		if (parse_line(line, scene, error) != RT_ERR_OK)
			return (free(line), close(fd), rt_error_print(error), error->code);
		free(line);
		line = get_next_line(fd);
		error->line++;
	}
	return (close(fd), RT_ERR_OK);
}
