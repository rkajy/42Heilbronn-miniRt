/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 01:00:13 by radandri          #+#    #+#             */
/*   Updated: 2026/06/30 02:12:43 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_split(char **parts)
{
	int	index;

	if (parts == NULL)
		return ;
	index = 0;
	while (parts[index] != NULL)
	{
		free(parts[index]);
		index++;
	}
	free(parts);
}
