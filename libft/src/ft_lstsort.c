/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:44:30 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 12:24:47 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *lst, int (*f)(t_list *, t_list *))
{
	int		sorted;
	t_list	*cur;

	sorted = 0;
	while (sorted == 0)
	{
		cur = lst;
		sorted = 1;
		while (cur)
		{
			if (f(cur, cur->next) == 1)
			{
				ft_lstswap(cur, cur->next);
				sorted = 0;
			}
			cur = cur->next;
		}
	}
}
