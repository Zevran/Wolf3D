/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 18:23:08 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:54:07 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	push_back(t_list **lst, t_list *elem)
{
	t_list	*ptr;
	t_list	*last;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	last = NULL;
	while (ptr)
	{
		last = ptr;
		ptr = ptr->next;
	}
	if (!last)
		*lst = elem;
	else
		last->next = elem;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p_cur;
	t_list	*p_dup;

	p_dup = ft_lstnew(NULL, 0);
	p_cur = lst;
	while (p_cur)
	{
		push_back(&p_dup, f(p_cur));
		p_cur = p_cur->next;
	}
	return (p_dup);
}
