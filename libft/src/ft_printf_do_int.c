/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:55:53 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/12 16:29:22 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>
#include <libft_converters.h>
#include <libft_printf.h>

static void		padded_print(int fd, int i, size_t width, int *counter)
{
	char	*buf;
	char	*ntoa;

	if (i < 0)
	{
		*counter += ft_putchar_fd('-', fd);
		ntoa = ft_ntoa((unsigned)-1, 10);
	}
	else
		ntoa = ft_ntoa((unsigned)i, 10);
	if (!width)
		buf = ft_strdup(ntoa);
	else
		buf = ft_strndup(ntoa, width);
	if (ft_strlen(buf) < width)
	{
		width -= ft_strlen(buf);
		while (--width)
			*counter += ft_putchar_fd('0', fd);
	}
	*counter += ft_putstr_fd(buf, fd);
	ft_strdel(&buf);
}

void			ft_printf_do_int(t_printf_parse_env *env, va_list args)
{
	int	i;

	i = va_arg(args, int);
	padded_print(env->fd, i, env->width, &env->ret);
}
