/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:46:17 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/18 10:46:33 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int				ft_error(const char *fmt, ...)
{
	va_list		args;
	int			done;

	va_start(args, fmt);
	done = ft_vfprintf(2, fmt, args);
	va_end(args);
	return (done);
}
