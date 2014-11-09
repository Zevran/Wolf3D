/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:22:10 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:35:22 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	ret;
	int	sign;

	if (!*str)
		return (0);
	sign = 1;
	ret = 0;
	while (ft_isanyof(*str, " \v\t\f\r\n"))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+' && sign > 0)
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (sign * ret);
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (sign * ret);
}
