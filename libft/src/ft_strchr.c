/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:53:40 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:53:33 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == (char)c)
			return ((char*)(str + i));
		i++;
	}
	return (NULL);
}
