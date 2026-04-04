/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 19:48:50 by radandri          #+#    #+#             */
/*   Updated: 2026/04/08 19:56:35 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

float ft_atof(const char *str);

int	is_file_extension_valid(const char *filename, const char *extension);
int	is_input_valid(int argc, char **argv);
int	is_input_parsed(int argc, char **argv, void *data);

#endif
