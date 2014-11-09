/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:14:28 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/19 15:14:53 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_dlist.h>
#include <libft_memory.h>

t_dlist	*ft_dlist_copy(t_dlist *dest, const t_dlist *source)
{
	const t_dnode	*cur;

	if (!source || !dest)
		return (dest);
	cur = source->tail;
	while (cur != source->head)
	{
		ft_dlist_add_back(dest, ft_dnode_new(ft_memdup(cur->data, cur->size),
												cur->size, cur->flag));
		cur = cur->next;
	}
	return (dest);
}
