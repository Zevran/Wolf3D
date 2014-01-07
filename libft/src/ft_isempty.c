/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:27:41 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:53:09 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isempty(char const *str)
{
	while (str && *str && ft_isspace(*str))
		str++;
	return ((*str == '\0') ? TRUE : FALSE);
}
