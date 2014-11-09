/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:26:14 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:56:27 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*p_cur;

	p_cur = dest + ft_strlen(dest);
	while (n-- && p_cur && src && *src)
		*(p_cur++) = *(src++);
	*p_cur = '\0';
	return (dest);
}
