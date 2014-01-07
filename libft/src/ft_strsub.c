/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:06:13 by greyrol           #+#    #+#             */
/*   Updated: 2013/11/30 19:34:46 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	size_t	slen;
	char	*p_s1;
	char	*p_ret;
	char	*ret;

	slen = ft_strlen(s1);
	if (((start + len) > slen))
		return (NULL);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	p_s1 = (char *) (s1 + start);
	p_ret = ret;
	while (len--)
		*(p_ret++) = *(p_s1++);
	*p_ret = '\0';
	return (ret);
}
