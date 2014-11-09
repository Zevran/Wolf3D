/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:45:07 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:43:05 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
		if (content && content_size)
		{
			list->content_size = content_size;
			list->content = malloc(list->content_size);
			if (list->content)
				ft_memcpy(list->content, content, content_size);
		}
	}
	return (list);
}
