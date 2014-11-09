/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 04:10:09 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:45:51 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>
#include <libft_converters.h>
#include <libft_printf.h>

void	ft_printf_do_char(t_printf_parse_env *env, va_list args)
{
	static int	c;
	int			i;

	i = 0;
	c = va_arg(args, int);
	while (i < (env->width ? (env->width - 1) : 0))
	{
		env->ret += ft_putchar_fd(' ', env->fd);
		i++;
	}
	env->ret += ft_putchar_fd(c, env->fd);
}
