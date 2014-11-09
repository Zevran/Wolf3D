/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:10:00 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:56:47 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = dest;
	while (i < n && dest && src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n && dest && src)
	{
		dest[i] = '\0';
		i++;
	}
	return (ptr);
}
