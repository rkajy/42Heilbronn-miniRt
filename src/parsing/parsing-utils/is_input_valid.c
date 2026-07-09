/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:43:35 by radandri          #+#    #+#             */
/*   Updated: 2026/07/09 13:21:26 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/libft/includes/libft.h"
#include "../../../include/error.h"
#include "../../../include/parse.h"
#include "../../../include/utils.h"

int	is_input_valid(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	return (is_file_extension_valid(argv[1], ".rt"));
}
