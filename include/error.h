/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:46:35 by radandri          #+#    #+#             */
/*   Updated: 2026/06/30 22:44:10 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_rt_error_code
{
	RT_ERR_OK = 0,
	RT_ERR_USAGE = 1,
	RT_ERR_INVALID_EXTENSION = 2,
	RT_ERR_FILE_OPEN = 3,
	RT_ERR_EMPTY_FILE = 4,
	RT_ERR_ALLOC = 5,
	RT_ERR_INVALID_FORMAT = 6,
	RT_ERR_UNKNOWN_IDENTIFIER = 7,
	RT_ERR_DUPLICATE_AMBIENT = 8,
	RT_ERR_DUPLICATE_CAMERA = 9,
	RT_ERR_DUPLICATE_LIGHT = 10,
	RT_ERR_MISSING_AMBIENT = 11,
	RT_ERR_MISSING_CAMERA = 12,
	RT_ERR_MISSING_LIGHT = 13,
	RT_ERR_INVALID_NUMBER = 14,
	RT_ERR_OUT_OF_RANGE = 15,
	RT_ERR_INVALID_VECTOR = 16,
	RT_ERR_INVALID_COLOR = 17,
	RT_ERR_TRAILING_DATA = 18
}					t_rt_error_code;

# define RT_ERRMSG_USAGE "usage: ./miniRT <scene.rt>"
# define RT_ERRMSG_INVALID_EXTENSION "invalid file extension (.rt expected)"
# define RT_ERRMSG_FILE_OPEN "cannot open scene file"
# define RT_ERRMSG_EMPTY_FILE "scene file is empty"
# define RT_ERRMSG_ALLOC "memory allocation failure"
# define RT_ERRMSG_INVALID_FORMAT "invalid scene format"
# define RT_ERRMSG_UNKNOWN_IDENTIFIER "unknown scene element"
# define RT_ERRMSG_DUPLICATE_AMBIENT "ambient lighting already defined"
# define RT_ERRMSG_DUPLICATE_CAMERA "camera already defined"
# define RT_ERRMSG_DUPLICATE_LIGHT "light already defined"
# define RT_ERRMSG_MISSING_AMBIENT "ambient lighting is missing"
# define RT_ERRMSG_MISSING_CAMERA "camera is missing"
# define RT_ERRMSG_MISSING_LIGHT "light is missing"
# define RT_ERRMSG_INVALID_NUMBER "invalid numeric value"
# define RT_ERRMSG_OUT_OF_RANGE "value out of allowed range"
# define RT_ERRMSG_INVALID_VECTOR "invalid vector value"
# define RT_ERRMSG_INVALID_COLOR "invalid color value"
# define RT_ERRMSG_TRAILING_DATA "unexpected trailing data"

typedef struct s_rt_error
{
	t_rt_error_code	code;
	const char		*message;
	int				line;
}					t_rt_error;

void				rt_error_init(t_rt_error *error);
void				rt_error_clear(t_rt_error *error);
int					rt_error_set(t_rt_error *error, t_rt_error_code code);
int					rt_error_set_at(t_rt_error *error, t_rt_error_code code,
						int line);
const char			*rt_error_message(t_rt_error_code code);
void				rt_error_print(const t_rt_error *error);

#endif