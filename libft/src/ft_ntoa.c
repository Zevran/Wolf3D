/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:47:44 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/26 16:06:59 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ntoa(unsigned long num, int base)
{
	static char	buf[65];
	char		*ptr;

	ptr = &buf[sizeof(buf) - 1];
	*ptr = '\0';
	while (1)
	{
		*--ptr = "0123456789abcdef"[num % base];
		num /= base;
		if (num == 0)
			break ;
	}
	return (ptr);
}
