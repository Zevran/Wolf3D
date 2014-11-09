/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_width.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 15:13:48 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 12:28:38 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_converters.h>
#include <libft_memory.h>
#include <libft_string.h>
#include "libft_printf.h"

static int			ft_printf_parse_isok(char **fmt, unsigned char counter)
{
	if (!fmt || !*fmt || !**fmt)
		return (0);
	return (ft_isdigit(**fmt) && counter < FT_PRINTF_MAX_WIDTH);
}

int					ft_printf_parse_width(char **fmt)
{
	char			buffer[FT_PRINTF_MAX_WIDTH + 1];
	unsigned char	counter;
	int				ret;

	ret = 0;
	counter = 0;
	ft_memset((void*)buffer, 0, FT_PRINTF_MAX_WIDTH);
	while (ft_printf_parse_isok(fmt, counter))
		buffer[counter++] = *((*fmt)++);
	while (fmt && *fmt && **fmt && ft_isdigit(**fmt))
		(*fmt)++;
	buffer[counter] = '\0';
	ret = ft_atoi(buffer);
	if (ret < 0)
		ret = 0;
	return (ret);
}
