/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:13:34 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/18 10:13:47 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_strmatch(const char *str, const char *pattern)
{
	if (!*str && !*pattern)
		return (TRUE);
	if (*str == *pattern)
		return (ft_strmatch(str + 1, pattern + 1));
	else if (*pattern == '*')
	{
		if (*(pattern + 1) == *(str + 1))
			return (ft_strmatch(str + 1, pattern + 1));
		else
			return (ft_strmatch(str + 1, pattern));
	}
	return (FALSE);
}
