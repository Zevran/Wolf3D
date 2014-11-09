/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:21:02 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/14 03:26:15 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>
#include <libft_string.h>

void	ft_vsnprintf_char(t_vsnprintf_env *env, va_list args, int caps)
{
	char			c;
	size_t			len;

	c = (char)va_arg(args, int);
	if (!env)
		return ;
	len = (c != 0);
	env->counter += len;
	if (env->counter < env->max)
		*env->offset = c && caps ? ft_toupper(c) : c;
	env->offset += len;
}
