/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 01:56:04 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/14 19:27:45 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_memory.h>
#include <libft_printf.h>

size_t	ft_vsnprintf(char **buffer, size_t max, const char *format,
					va_list args)
{
	static t_vsnprintf_env	env;

	ft_memset(&env, 0, sizeof(env));
	if (!*format)
		return (0);
	if (!buffer || !*buffer)
		return (0);
	env.buffer = *buffer;
	env.max = max;
	env.format = format;
	env.counter = 0;
	env.offset = env.buffer;
	return (ft_vsnprintf_loop(&env, args));
}

size_t	ft_snprintf(char **buffer, size_t max, const char *format, ...)
{
	int				ret;
	va_list			args;

	va_start(args, format);
	ret = ft_vsnprintf(buffer, max, format, args);
	va_end(args);
	return (ret);
}
