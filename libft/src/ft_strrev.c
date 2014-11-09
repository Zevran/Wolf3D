/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 20:37:56 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:57:56 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*pcur;
	char	*pend;

	pcur = str;
	pend = str + (ft_strlen(str) - 1);
	if (!*str)
		return (str);
	while (pcur != pend)
	{
		ft_swapc(pcur, pend);
		pcur++;
		pend--;
	}
	return (str);
}
