/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_printf_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 15:18:49 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:45:37 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_string.h>
#include <libft_memory.h>

static int	ft_parse_printf_char1(t_printf_parse_env *env, va_list args)
{
	if (**env->fmt == 's')
		ft_printf_do_string(env, args);
	else if (**env->fmt == 'c')
		ft_printf_do_char(env, args);
	else if (**env->fmt == 'i' || **env->fmt == 'd')
		ft_printf_do_int(env, args);
	else if (**env->fmt == 'b')
		ft_printf_do_bool(env, args);
	else if (**env->fmt == 'B')
		ft_printf_do_number(env, args, 2, 0);
	else
		return (0);
	return (1);
}

static int	ft_parse_printf_char2(t_printf_parse_env *env, va_list args)
{
	if (**env->fmt == 'p' || **env->fmt == 'P')
		ft_printf_do_pointer(env, args, ft_isupper(**env->fmt));
	else if (**env->fmt == 'i' || **env->fmt == 'd')
		ft_printf_do_int(env, args);
	else if (**env->fmt == 'o' || **env->fmt == 'O')
		ft_printf_do_number(env, args, 8, ft_isupper(**env->fmt));
	else if (**env->fmt == 'x' || **env->fmt == 'X')
		ft_printf_do_number(env, args, 16, ft_isupper(**env->fmt));
	else if (**env->fmt == 'u' || **env->fmt == 'U')
		ft_printf_do_number(env, args, 10, ft_isupper(**env->fmt));
	else
		return (0);
	return (1);
}

int			ft_parse_printf_char(int fd, char **fmt, va_list args)
{
	t_printf_parse_env	env;

	env.fd = fd;
	env.fmt = fmt;
	env.ret = 0;
	if (**fmt == '%')
	{
		(*fmt)++;
		env.width = ft_printf_parse_width(fmt);
		if (!ft_parse_printf_char1(&env, args))
		{
			if (!ft_parse_printf_char2(&env, args))
				env.ret += ft_putchar_fd(**fmt, fd);
		}
	}
	else
		env.ret += ft_putchar_fd(**fmt, fd);
	return (env.ret);
}
