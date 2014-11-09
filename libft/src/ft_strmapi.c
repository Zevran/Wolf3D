/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:52:37 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:56:07 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	id;
	size_t	len;

	len = ft_strlen(str);
	id = 0;
	ret = ft_strdup(str);
	if (!ret)
		return (NULL);
	while (id < len)
	{
		ret[id] = f(id, ret[id]);
		id++;
	}
	return (ret);
}
