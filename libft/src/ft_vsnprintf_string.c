/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:21:37 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/14 03:58:48 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_string.h>
#include <libft_printf.h>

void	ft_vsnprintf_string(t_vsnprintf_env *env, va_list args, int caps)
{
	char	*s;
	size_t	len;

	s = (char*)va_arg(args, char*);
	if (!s || !env)
		return ;
	len = ft_strlen(s);
	ft_strncpy(env->offset, caps ? ft_strtoupper(s) : s, env->max);
	env->counter += len;
	env->offset += len;
}
