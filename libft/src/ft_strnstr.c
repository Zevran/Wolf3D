/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:07:09 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/01 21:01:46 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstack, const char *needle, size_t n)
{
	char	*start;
	char	*max;
	size_t	nlen;

	nlen = ft_strlen(needle);
	max = (char *) (hstack + n);
	if (!needle || !nlen || !hstack)
		return ((char *) hstack);
	start = (char *) hstack;
	while ((start = ft_strchr(start, *needle)) && start <= max)
	{
		if (start + nlen <= max && !ft_strncmp(start, needle, nlen))
			return (start);
		start++;
	}
	return (NULL);
}
