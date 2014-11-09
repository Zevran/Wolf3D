/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:43:45 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/24 13:42:33 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const t_uchar	*psrc;
	t_uchar			*pdest;

	psrc = (const t_uchar*)src;
	pdest = (t_uchar*)dest;
	if (pdest <= psrc || pdest >= (psrc + n))
	{
		while (n-- && psrc && pdest)
			*(pdest++) = *(psrc++);
	}
	else
	{
		psrc += n - 1;
		pdest += n - 1;
		while (n-- && psrc && pdest)
			*(pdest--) = *(psrc--);
	}
	return (dest);
}
