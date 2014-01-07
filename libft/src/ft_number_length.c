/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:48:23 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 14:11:05 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"

size_t	ft_nbrlen(long int num, int base)
{
	size_t	i;

	i = 0;
	if (num <= 0)
			i++;
	while (num)
	{
		i++;
		num /= base;
	}
	return (i);
}

size_t	ft_nbrlen_u(long unsigned int num, int base)
{
	size_t	i;

	i = 0;
	if (num <= 0)
			i++;
	while (num)
	{
		i++;
		num /= base;
	}
	return (i);
}
