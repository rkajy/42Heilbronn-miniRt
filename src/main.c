/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:32:29 by asando            #+#    #+#             */
/*   Updated: 2026/06/16 19:01:12 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"
#include "parse.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\f' || c == '\v');
}

bool	is_comment_or_empty(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '#' || line[i] == '\0' || line[i] == '\n')
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	if (!is_input_valid(argc, argv))
	{
		fprintf(stderr, "usage: ./miniRT <scene.rt>\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_comment_or_empty(line))
		{
			printf("%s", line);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
