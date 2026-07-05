/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 01:03:21 by radandri          #+#    #+#             */
/*   Updated: 2026/07/05 04:59:25 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

double	ft_atof(const char *str);
void	free_split(char **parts);
char	*clean_line(char *line);
bool	is_comment_or_empty(char *line);
bool	ft_isspace(char c);
int		is_file_extension_valid(const char *filename, const char *extension);
int		is_input_valid(int argc, char **argv);
#endif