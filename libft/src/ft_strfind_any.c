/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 11:20:02 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/19 11:20:25 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>

int	ft_strfind_any(char *str, char const *seps, int offset)
{
	int	found;

	found = -1;
	if (!str || !seps)
		return (found);
	while (seps && *seps && (found = ft_strfind(str, *seps, offset)) == -1)
		seps++;
	return (found);
}
