/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_bool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:55:14 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/12 16:28:14 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>
#include <libft_printf.h>

void	ft_printf_do_bool(t_printf_parse_env *env, va_list args)
{
	char	*y;
	char	*n;
	int		i;

	i = va_arg(args, int);
	y = ft_strdup("true");
	n = ft_strdup("false");
	env->ret += ft_putstr_fd(i ? y : n, env->fd);
	if (y)
		ft_strdel(&y);
	if (n)
		ft_strdel(&n);
}
