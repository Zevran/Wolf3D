/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:54:07 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/19 02:43:17 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_string.h>
#include <stdarg.h>

void	ft_printf_do_string(t_printf_parse_env *env, va_list args)
{
	char			*s;
	char			*buf;
	int				width;

	s = va_arg(args, char *);
	width = env->width;
	if (!width)
		buf = ft_strdup(s);
	else
		buf = ft_strndup(s, width);
	if (ft_strlen(s) < (size_t)width)
	{
		width -= ft_strlen(s);
		while (--width)
			env->ret += ft_putchar_fd(' ', env->fd);
	}
	env->ret += ft_putstr_fd(buf, env->fd);
	ft_strdel(&buf);
}
