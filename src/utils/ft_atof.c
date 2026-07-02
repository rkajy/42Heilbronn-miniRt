/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:02 by radandri          #+#    #+#             */
/*   Updated: 2026/07/03 00:14:06 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/includes/libft.h"

double	ft_atof(const char *str)
{
	int		l = 0, r;
	int		a;
	double	b;

	l = 0, r = ft_strlen(str) - 1;
	a = 0;
	b = 0;
	while ('0' <= str[l] && str[l] <= '9')
	{
		a = (a * 10) + str[l] - '0';
		l++;
	}
	while (('0' <= str[r] && str[r] <= '9') || str[r] == '.')
	{
		if (str[r] != '.')
			b = b * 0.1 + str[r] - '0';
		else
		{
			b *= 0.1;
			break ;
		}
		r--;
	}
	return (a + b);
}
