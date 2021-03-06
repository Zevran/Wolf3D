/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 10:25:23 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/28 10:25:46 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list		*ft_lstback(t_list *l)
{
	t_list		*i;

	i = l;
	while (i && i->next)
		i = i->next;
	return (i);
}
