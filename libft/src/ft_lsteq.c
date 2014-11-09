/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsteq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 07:32:45 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/16 07:38:04 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bool			ft_lsteq(t_list *a, t_list *b, t_content_comparator comp)
{
	while (a && b)
	{
		if (comp(a->content, b->content) == FALSE)
			return (FALSE);
		a = a->next;
		b = b->next;
	}
	return (TRUE);
}
