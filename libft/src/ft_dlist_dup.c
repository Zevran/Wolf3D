/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:13:53 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/19 15:14:13 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_memory.h>
#include <libft_dlist.h>

t_dlist	*ft_dlist_dup(const t_dlist *source)
{
	t_dlist	*copy;

	copy = (t_dlist*)ft_memalloc(sizeof(t_dlist));
	ft_dlist_init(copy);
	return (ft_dlist_copy(copy, source));
}
