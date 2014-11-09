/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 04:21:13 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/15 02:56:31 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_string.h>
#include <libft_converters.h>

void	ft_vsnprintf_float(t_vsnprintf_env *env, va_list args)
{
	double		f;
	size_t		len;

	f = (double)va_arg(args, double);
	if (!env)
		return ;
	ft_strncpy(env->offset, ft_ftoa(f, 4), env->max);
	len = ft_strlen(env->offset);
	env->offset += len;
	env->counter += len;
}
