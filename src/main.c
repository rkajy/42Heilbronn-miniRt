/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:32:29 by asando            #+#    #+#             */
/*   Updated: 2026/07/03 01:23:07 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"
#include "parse.h"
#include <fcntl.h>
#include <stdio.h>
#include "../include/utils.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (!is_input_valid(argc, argv))
		return (printf("Error\n%s\n", RT_ERRMSG_USAGE), RT_ERR_USAGE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (printf("Error\n%s\n", RT_ERRMSG_FILE_OPEN), RT_ERR_FILE_OPEN);
	line = NULL;
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
