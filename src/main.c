/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:32:29 by asando            #+#    #+#             */
/*   Updated: 2026/03/23 18:32:36 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_rt.h"
#include "parse.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	result;

	result = add_demo_values(20, 22);
	printf("demo result: %d\n", result);
	if (!is_input_valid(argc, argv))
	{
		fprintf(stderr, "usage: ./miniRT <scene.rt>\n");
		return (1);
	}
	if (!is_input_parsed(argc, argv, NULL))
	{
		fprintf(stderr, "failed to parse input\n");
		return (1);
	}
	return (0);
}
