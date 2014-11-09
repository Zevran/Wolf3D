/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:11:31 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:57:32 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*start;
	const char	*end;
	const char	*cur;

	start = str;
	if (!str)
		return ((char*)str);
	end = str + (ft_strlen(str) ? ft_strlen(str) : 0);
	cur = end;
	while (cur && cur >= start)
	{
		if (*cur == (char)c)
			return ((char*)cur);
		cur--;
	}
	return (NULL);
}
