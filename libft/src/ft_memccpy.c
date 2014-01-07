/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:35:41 by greyrol           #+#    #+#             */
/*   Updated: 2013/11/26 18:15:36 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	const unsigned char	*psrc;
	unsigned char		*pdest;
	unsigned char		i;

	if (!n)
		return (NULL);
	psrc = (const t_uchar *) s2;
	pdest = (t_uchar *) s1;
	i = (size_t)c;
	while (n)
	{
		if ((*pdest++ = *psrc++) == i)
			return (pdest);
		n--;
	}
	return (NULL);
}
