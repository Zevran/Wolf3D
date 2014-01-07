/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:54:41 by greyrol           #+#    #+#             */
/*   Updated: 2013/11/23 21:53:54 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	t_uchar		*pstart;
	t_uchar		*pend;

	if (!b || !len)
		return (b);
	pstart = (unsigned char *) b;
	pend = pstart + len;
	while (pstart != pend)
	{
		*pstart = (unsigned char) c;
		pstart++;
	}
	return (b);
}
