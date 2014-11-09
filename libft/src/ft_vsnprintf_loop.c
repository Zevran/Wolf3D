/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:23:29 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 12:07:05 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>

size_t	ft_vsnprintf_loop(t_vsnprintf_env *env, va_list args)
{
	if (!env)
		return (0);
	while (*env->format)
	{
		if (*env->format == '%')
		{
			env->format++;
			ft_vsnprintf_step(env, args);
		}
		else
		{
			*env->offset++ = *env->format;
			env->counter++;
			env->format++;
		}
	}
	return (env->counter);
}
