/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 01:09:51 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 16:00:45 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_converters.h"
#include "libft_printf.h"

int	ft_fprintf(int fd, const char *fmt, ...)
{
	int			return_i;
	va_list		args;

	va_start(args, fmt);
	return_i = ft_parse(fd, (char *) fmt, args);
	va_end(args);
	return (return_i);
}

int	ft_printf(char *format, ...)
{
	int	return_i;
	va_list	ap;

	va_start(ap, format);
	return_i = ft_parse(1, format, ap);
	va_end(ap);
	return (return_i);
}
