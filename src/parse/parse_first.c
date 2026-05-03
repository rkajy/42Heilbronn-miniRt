/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:43:35 by radandri          #+#    #+#             */
/*   Updated: 2026/05/03 17:00:41 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/libft/includes/libft.h"
#include "parse.h"

int	is_file_extension_valid(const char *filename, const char *extension)
{
	int	filename_len;
	int	extension_len;
	int	index;

	if (!filename || !extension)
		return (0);
	filename_len = ft_strlen(filename);
	extension_len = ft_strlen(extension);
	if (filename_len <= extension_len)
		return (0);
	index = 0;
	while (extension[index] != '\0')
	{
		if (filename[filename_len - extension_len + index] != extension[index])
			return (0);
		index++;
	}
	return (1);
}

int	is_input_valid(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	return (is_file_extension_valid(argv[1], ".rt"));
}

int	is_input_parsed(int argc, char **argv, void *data)
{
	(void)argc;
	(void)argv;
	(void)data;
	return (1);
}
