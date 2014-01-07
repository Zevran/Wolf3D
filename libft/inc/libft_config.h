/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_config.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:30:15 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/28 10:10:18 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CONFIG_H
# define LIBFT_CONFIG_H

# include <string.h>
# include <stdlib.h>

# define FT_INVALID_STR "(null)"

# define FT_USE_PRINTF
# define FT_USE_FILESYSTEM
# define FT_USE_STRINGS
# define FT_USE_LINKED_LISTS

# define FT_BUF_MAX		4096
# define FT_TOK_MAX		1024

# define FT_MIN(a, b)	(a < b ? a : b)
# define FT_MAX(a, b)	(a > b ? a : b)

typedef unsigned long	t_ulong;
typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;

typedef	t_uint			*t_uint_ptr;
typedef t_uchar			*t_uchar_ptr;
typedef t_ushort		*t_ushort_ptr;
typedef t_ulong			*t_ulong_ptr;

typedef enum			s_bool
{
	FALSE,
	TRUE
}						t_bool;


#endif /* !LIBFT_CONFIG_H */
