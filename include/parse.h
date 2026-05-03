/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:48:50 by radandri          #+#    #+#             */
/*   Updated: 2026/05/03 17:01:12 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_sphere
{
	t_vector	center;
	float		radius;
	t_color		color;
}				t_sphere;

float			ft_atof(const char *str);

int				is_file_extension_valid(const char *filename,
					const char *extension);
int				is_input_valid(int argc, char **argv);
int				is_input_parsed(int argc, char **argv, void *data);

#endif
