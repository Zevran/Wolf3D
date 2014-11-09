/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:48:23 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:45:14 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"

size_t	ft_number_length(unsigned long num, int base)
{
	static char		buf[65] = {0};
	char			*ptr;
	size_t			ret;

	ret = 0;
	ptr = &buf[sizeof(buf) - 1];
	*ptr = '\0';
	while (1)
	{
		*--ptr = "0123456789abcdef"[num % base];
		ret++;
		num /= base;
		if (num == 0)
			break ;
	}
	return (ret);
}
