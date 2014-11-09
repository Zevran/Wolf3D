/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 15:15:39 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/12 15:19:15 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>

int				ft_fprintf(int fd, const char *fmt, ...)
{
	int		ret;
	va_list	args;

	va_start(args, fmt);
	ret = (ft_vfprintf(fd, fmt, args));
	va_end(args);
	return (ret);
}
