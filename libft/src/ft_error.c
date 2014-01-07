/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:46:17 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:51:44 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_error(const char *fmt, ...)
{
	va_list		args;
	int			return_i;

	va_start(args, fmt);
	return_i = ft_parse(2, (char *)fmt, args);
	va_end(args);
	return (return_i);
}
