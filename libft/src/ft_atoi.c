/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:22:10 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 14:07:55 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	is_neg;
	int	i_nbr;

	is_neg = 0;
	i_nbr = 0;
	while (ft_isanyof(*str, " \v\t\f\r\n"))
		str++;
	if (*str == '-')
	{
		is_neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i_nbr = i_nbr * 10 + (*str - '0');
		str++;
	}
	return (i_nbr * is_neg);
}
