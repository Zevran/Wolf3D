/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:22:18 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/14 03:24:56 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>
#include <libft_string.h>
#include <libft_converters.h>

void	ft_vsnprintf_unsigned(t_vsnprintf_env *env, va_list args, int base)
{
	unsigned long	i;
	size_t			len;

	i = (unsigned long)va_arg(args, unsigned long);
	if (!env)
		return ;
	len = ft_number_length(i, base);
	ft_strncpy(env->offset, ft_ntoa(i, base), env->max);
	env->offset += len;
	env->counter += len;
}
