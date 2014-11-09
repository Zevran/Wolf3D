/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:44:58 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 12:25:40 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t s))
{
	t_list	*ptr;

	if (!alst || !*alst)
		return ;
	ptr = *alst;
	if (ptr->content)
		del(ptr->content, ptr->content_size);
	ft_memdel((void**)alst);
}
