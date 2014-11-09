/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:21:42 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/18 17:51:47 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_dlist.h"

t_dnode	*ft_dnode_init(t_dnode *n, void *data, size_t size, int flags)
{
	if (!n)
		return (n);
	n->prev = NULL;
	n->next = NULL;
	n->size = size;
	n->data = data;
	n->flag = flags;
	return (n);
}

t_dnode	*ft_dnode_new(void *data, size_t size, int flags)
{
	t_dnode	*ret;

	ret = (t_dnode*)malloc(sizeof(t_dnode));
	if (!ret)
		return (ret);
	ft_dnode_init(ret, data, size, flags);
	return (ret);
}
