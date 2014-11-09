/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 04:10:21 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/14 23:50:59 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

typedef unsigned long		t_ulong;
typedef unsigned int		t_uint;
typedef unsigned char		t_uchar;
typedef unsigned short		t_ushort;

typedef t_uint				*t_uint_ptr;
typedef t_uchar				*t_uchar_ptr;
typedef t_ushort			*t_ushort_ptr;
typedef t_ulong				*t_ulong_ptr;

typedef long				t_int64;
typedef int					t_int32;
typedef short				t_int16;
typedef char				t_int8;

typedef t_ulong				t_uint64;
typedef t_uint				t_uint32;
typedef t_ushort			t_uint16;
typedef t_uchar				t_uint8;

# if !defined(REAL_DEFINED)
#  if defined(USE_DOUBLE) || defined(DOUBLE_PRECISION)
typedef double				t_real;
#  else
typedef float				t_real;
#  endif
#  define REAL_DEFINED
# endif
typedef enum				s_bool
{
	FALSE,
	TRUE
}							t_bool;

#endif /* !LIBFT_TYPES_H */
