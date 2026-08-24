/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_extension_valid.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 19:50:01 by radandri          #+#    #+#             */
/*   Updated: 2026/08/24 20:23:12 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/error.h"
#include "../../../include/parse.h"
#include "../../../lib/libft/includes/libft.h"

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
