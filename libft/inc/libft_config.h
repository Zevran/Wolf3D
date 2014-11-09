/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_config.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:30:15 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/19 11:17:24 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CONFIG_H
# define LIBFT_CONFIG_H

# include <string.h>
# include "libft_version.h"
# include "libft_types.h"
# include "libft_platform.h"

# if defined(_DEBUG) && !defined(NDEBUG)
#  define LIBFT_DEBUG
#  define FT_DEBUG
# else
#  define LIBFT_RELEASE
#  define FT_RELEASE
# endif

# define FT_INVALID_STR "(null)"
# define FT_WHITESPACE_SEPS " \n\v\f\t"

/*
** CORE CONFIG
*/

# define FT_USE_PRINTF
# define FT_USE_FILESYSTEM
# define FT_USE_STRINGS
# define FT_USE_LINKED_LISTS

# ifdef FT_DEBUG
#  ifdef FT_USE_FILESYSTEM
#   define FT_DEBUG_FILESYSTEM
#  endif
#  ifdef FT_USE_STRINGS
#   define FT_DEBUG_STRING
#  endif
#  ifdef FT_USE_PRINTF
#   define FT_DEBUG_PRINTF
#  endif
#  ifdef FT_USE_LINKED_LISTS
#   define FT_DEBUG_LINKED_LISTS
#  endif
# endif

# define FT_BUF_MAX		4096
# define FT_TOK_MAX		1024
# define FT_PATH_MAX	260

# define FT_MIN(a, b)	(a < b ? a : b)
# define FT_MAX(a, b)	(a > b ? a : b)

#endif
