/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:45:07 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:54:40 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	ret = (t_list*)ft_memalloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	if (!content || !content_size)
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	else
	{
		ret->content_size = content_size;
		ret->content = (void*)content;
	}
	ret->next = NULL;
	return (ret);
}
