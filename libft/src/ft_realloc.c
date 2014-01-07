/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:11:55 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/18 10:18:24 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*dup;

	dup = ft_memalloc(size);
	if (dup && size)
	{
		if (ptr)
			ft_memcpy(dup, ptr, size);
		else
			ft_memset(dup, 0, size);
	}
	if (ptr)
		ft_memdel(&ptr);
	return (dup);
}
