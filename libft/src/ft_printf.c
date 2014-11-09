/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 06:43:07 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/12 15:19:02 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <libft_printf.h>
#include <stdio.h>

int				ft_printf(const char *fmt, ...)
{
	int		ret;
	va_list	args;

	va_start(args, fmt);
	ret = (ft_vprintf(fmt, args));
	va_end(args);
	return (ret);
}
