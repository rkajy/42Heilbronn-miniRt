/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:00:22 by radandri          #+#    #+#             */
/*   Updated: 2026/08/27 19:57:14 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parse_functions.h"
#include "get_next_line_bonus.h"
#include "utils.h"
#include <fcntl.h>

static int	parse_non_empty_line(char *line, t_scene *scene, t_rt_error *error)
{
	char	*clean;

	clean = clean_line(line);
	if (parse_line(clean, scene, error) != RT_ERR_OK)
		return (error->code);
	return (RT_ERR_OK);
}

int	parse_file(const char *filename, t_scene *scene, t_rt_error *error)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (rt_error_set(error, RT_ERR_FILE_OPEN));
	error->line = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_comment_or_empty(line))
		{
			free(line);
			line = get_next_line(fd);
			error->line++;
			continue ;
		}
		if (parse_non_empty_line(line, scene, error) != RT_ERR_OK)
			return (free(line), close(fd), error->code);
		free(line);
		line = get_next_line(fd);
		error->line++;
	}
	return (close(fd), RT_ERR_OK);
}
