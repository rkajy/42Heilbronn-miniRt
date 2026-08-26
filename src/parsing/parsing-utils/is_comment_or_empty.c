/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment_or_empty.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 01:22:11 by radandri          #+#    #+#             */
/*   Updated: 2026/08/26 20:21:25 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "utils.h"

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
