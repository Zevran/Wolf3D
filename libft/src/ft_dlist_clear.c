/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:15:08 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 12:24:07 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_dlist.h>

void	ft_dlist_clear(t_dlist *list, t_dnode_deleter deleter)
{
	t_dnode	*cur;

	cur = list->tail;
	while (cur != list->head)
	{
		ft_dlist_remove(list, cur, deleter);
		cur = cur->next;
	}
}
