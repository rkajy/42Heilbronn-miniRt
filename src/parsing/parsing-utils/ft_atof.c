/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:51:02 by radandri          #+#    #+#             */
/*   Updated: 2026/07/07 22:53:23 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atof(const char *str)
{
	double	sign;
	double	value;
	double	factor;

	sign = 1.0;
	value = 0.0;
	factor = 0.1;
	if (*str == '-' || *str == '+')
		sign = -1.0 + (*str++ == '+') * 2.0;
	while (*str >= '0' && *str <= '9')
		value = value * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		while (*++str >= '0' && *str <= '9')
		{
			value += (*str - '0') * factor;
			factor *= 0.1;
		}
	}
	return (sign * value);
}
