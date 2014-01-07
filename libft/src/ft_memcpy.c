/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:52:31 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/04 13:30:11 by greyrol         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dptr;
	const char	*sptr;

	dptr = (char *) dest;
	sptr = (const char *) src;
	while (n-- && sptr && dptr)
		*dptr++ = *sptr++;
	return (dest);
}
