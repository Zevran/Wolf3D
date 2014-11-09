/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:18:04 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/19 11:13:03 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_dlist.h>
#include <libft_printf.h>

t_dnode	*ft_dlist_push_front(t_dlist *list, t_dnode *new_node)
{
	return (ft_dlist_add_front(list, new_node));
}

t_dnode	*ft_dlist_add_front(t_dlist *list, t_dnode *new_node)
{
	if (!list || !new_node)
		return (NULL);
	list->size++;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (!list->tail)
	{
		list->tail = new_node;
		list->head = new_node;
	}
	else
	{
		new_node->next = list->tail;
		list->tail->prev = new_node;
		list->tail = new_node;
	}
	return (new_node);
}
