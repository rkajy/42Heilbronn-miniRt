/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 01:17:33 by radandri          #+#    #+#             */
/*   Updated: 2026/07/03 05:06:16 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include "../../lib/libft/includes/libft.h"

static char	*skip_space_at_start(char *line)
{
	while (ft_isspace(*line))
		line++;
	return (line);
}

static void	remove_new_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	line[i] = '\0';
}

char	*clean_line(char *line)
{
	remove_new_line(line);
	line = skip_space_at_start(line);
	return (line);
}
