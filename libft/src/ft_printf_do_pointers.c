/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_pointers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 03:00:29 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/12 16:26:46 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include "libft_converters.h"
#include <stdarg.h>

void	ft_printf_do_pointer(t_printf_parse_env *env, va_list args, int caps)
{
	char			*s;
	unsigned long	l;

	l = va_arg(args, unsigned long);
	env->ret += ft_putstr_fd("0x", env->fd);
	s = ft_ntoa(l >> 16, 16);
	env->ret += ft_putstr_fd(caps ? ft_strtoupper(s) : s, env->fd);
	s = ft_ntoa(l & 0xffff, 16);
	env->ret += ft_putstr_fd(caps ? ft_strtoupper(s) : s, env->fd);
}
