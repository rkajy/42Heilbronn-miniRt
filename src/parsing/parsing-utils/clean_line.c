/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 01:17:33 by radandri          #+#    #+#             */
/*   Updated: 2026/07/09 13:19:48 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"
#include "../../../lib/libft/includes/libft.h"
#include <stdlib.h>

static char	*skip_space_at_start(char *line)
{
	size_t	start;

	start = 0;
	while (ft_isspace(line[start]))
		start++;
	if (start > 0)
		ft_memmove(line, line + start, ft_strlen(line + start) + 1);
	return (line);
}

static void	remove_new_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	line[i] = '\0';
}

char	*clean_line(char *line)
{
	remove_new_line(line);
	line = skip_space_at_start(line);
	return (line);
}
