/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strltrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:23:44 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/19 11:23:53 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

char	*ft_strltrim(char *str, char const *separators)
{
	char	*ptr;

	while (str && ft_isanyof(*str, separators))
	{
		ptr = str;
		while (ptr && *ptr)
		{
			*ptr = *(ptr + 1);
			ptr++;
		}
	}
	return (str);
}
