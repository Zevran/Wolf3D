/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 15:14:33 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 12:06:41 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>

int				ft_vfprintf(int fd, const char *fmt, va_list args)
{
	int		ret;
	char	*sptr;

	sptr = (char*)fmt;
	ret = 0;
	while (sptr && *sptr)
	{
		ret += ft_parse_printf_char(fd, &sptr, args);
		sptr++;
	}
	return (ret);
}
