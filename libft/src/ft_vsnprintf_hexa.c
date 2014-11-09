/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:22:47 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/14 05:40:46 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>
#include <libft_string.h>
#include <libft_converters.h>

void	ft_vsnprintf_hexa(t_vsnprintf_env *env, va_list args, int caps, int ptr)
{
	unsigned long	i;
	unsigned long	next;
	size_t			len;
	char			*str;

	i = (unsigned long)va_arg(args, unsigned long);
	if (!env)
		return ;
	next = i;
	if (ptr)
	{
		next = i & 0xffff;
		str = ft_ntoa(i >> 16, 16);
		len = ft_strlen(str);
		ft_strncpy(env->offset, caps ? ft_strtoupper(str) : str, env->max);
		env->offset += len;
		env->counter += len;
	}
	str = ft_ntoa(next, 16);
	len = ft_strlen(str);
	ft_strncpy(env->offset, caps ? ft_strtoupper(str) : str, env->max);
	env->offset += len;
	env->counter += len;
}
