/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:17:15 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/19 11:13:23 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_dlist.h>
#include <libft_printf.h>

t_dnode	*ft_dlist_push_back(t_dlist *list, t_dnode *new_node)
{
	return (ft_dlist_add_back(list, new_node));
}

t_dnode	*ft_dlist_add_back(t_dlist *list, t_dnode *new_node)
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
		new_node->prev = list->head;
		list->head->next = new_node;
		list->head = new_node;
	}
	return (new_node);
}
