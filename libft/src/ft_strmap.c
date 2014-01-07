/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:52:37 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:58:08 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char	*ret;
	size_t	id;
	size_t	len;

	id = 0;
	len = ft_strlen(str);
	ret = ft_strdup(str);
	if (!ret)
		return (NULL);
	while (id < len)
	{
		ret[id] = f(ret[id]);
		id++;
	}
	return (ret);
}
