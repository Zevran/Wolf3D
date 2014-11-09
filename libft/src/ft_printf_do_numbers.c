/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:59:02 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/12 16:26:03 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include "libft_converters.h"
#include <stdarg.h>

static void	padded_print(t_padd *padd, size_t width, int *counter)
{
	char	*s;
	char	*ntoa;

	ntoa = ft_ntoa(padd->num, padd->base);
	ntoa = padd->caps ? ft_strtoupper(ntoa) : ntoa;
	if (!width)
		s = ft_strdup(ntoa);
	else
		s = ft_strndup(ntoa, width);
	if (ft_strlen(s) < width)
	{
		width -= ft_strlen(s);
		while (--width)
			*counter += ft_putchar_fd('0', padd->fd);
	}
	*counter += ft_putstr_fd(s, padd->fd);
	ft_strdel(&s);
}

void		ft_printf_do_number(t_printf_parse_env *env, va_list args, int base,
								int caps)
{
	t_uint	num;
	t_padd	padd;

	num = va_arg(args, t_uint);
	padd.fd = env->fd;
	padd.num = num;
	padd.base = base;
	padd.caps = caps;
	padded_print(&padd, env->width, &env->ret);
}
