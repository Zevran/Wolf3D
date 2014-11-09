/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 05:14:48 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/03 05:15:16 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memrealloc(void *buf, size_t size)
{
	void	*tmp;

	if (!buf)
		return (ft_memalloc(size));
	if (!size && buf)
	{
		ft_memdel(&buf);
		return (buf);
	}
	tmp = ft_memalloc(size);
	ft_memcpy(tmp, buf, size);
	ft_memdel(&buf);
	return (tmp);
}
