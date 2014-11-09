/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:27:10 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/26 18:04:47 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include <stdlib.h>

void	ft_tokdel(char ***array)
{
	char	**next;
	char	***orig;

	orig = array;
	if (!array || !*array)
		return ;
	while (**array)
	{
		next = (*array) + 1;
		ft_strdel(*array);
		array = &next;
	}
	free (*orig);
	*array = NULL;
}
