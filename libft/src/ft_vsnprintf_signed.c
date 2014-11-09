/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:21:59 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/14 04:47:10 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>
#include <libft_string.h>
#include <libft_converters.h>

void	ft_vsnprintf_signed(t_vsnprintf_env *env, va_list args, int base)
{
	long		i;
	size_t		len;

	i = (long)va_arg(args, long);
	if (!env)
		return ;
	len = ft_number_length((unsigned long)i, base);
	if (i < 0)
		len += 1;
	env->counter += len;
	if (i < 0)
		*env->offset++ = '-';
	ft_strncpy(env->offset, ft_ntoa((unsigned long)i, base), env->max);
	env->offset += len;
	env->counter += len;
}
