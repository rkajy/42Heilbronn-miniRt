/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 23:54:35 by radandri          #+#    #+#             */
/*   Updated: 2026/06/30 23:54:38 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"
#include <stddef.h>

const char	*rt_error_message(t_rt_error_code code)
{
	static const char	*messages[] = {
		"ok",
		RT_ERRMSG_USAGE,
		RT_ERRMSG_INVALID_EXTENSION,
		RT_ERRMSG_FILE_OPEN,
		RT_ERRMSG_EMPTY_FILE,
		RT_ERRMSG_ALLOC,
		RT_ERRMSG_INVALID_FORMAT,
		RT_ERRMSG_UNKNOWN_IDENTIFIER,
		RT_ERRMSG_DUPLICATE_AMBIENT,
		RT_ERRMSG_DUPLICATE_CAMERA,
		RT_ERRMSG_DUPLICATE_LIGHT,
		RT_ERRMSG_MISSING_AMBIENT,
		RT_ERRMSG_MISSING_CAMERA,
		RT_ERRMSG_MISSING_LIGHT,
		RT_ERRMSG_INVALID_NUMBER,
		RT_ERRMSG_OUT_OF_RANGE,
		RT_ERRMSG_INVALID_VECTOR,
		RT_ERRMSG_INVALID_COLOR,
		RT_ERRMSG_TRAILING_DATA
	};

	if (code < RT_ERR_OK || code > RT_ERR_TRAILING_DATA)
		return (NULL);
	return (messages[(int)code]);
}
