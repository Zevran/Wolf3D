/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:23:19 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/19 11:23:29 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

char	*ft_strrot(char *str, size_t num_rots)
{
	char	*ptr;

	if (!num_rots)
		return (str);
	while (num_rots)
	{
		ptr = str;
		while (ptr && *ptr)
		{
			*ptr = *(ptr + 1);
			ptr++;
		}
		num_rots--;
	}
	return (str);
}
