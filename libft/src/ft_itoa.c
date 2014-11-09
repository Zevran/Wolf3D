/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:30:49 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:41:17 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbr_size(int dig)
{
	int			ret;
	int			temp;

	temp = dig;
	ret = 0;
	if (dig < 0 || !dig)
		ret++;
	while (temp)
	{
		ret++;
		temp /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char				*ret;
	int					neg;
	int					num_chars;
	int					temp;
	unsigned int		v;

	ret = NULL;
	neg = ((n < 0) ? 1 : 0);
	num_chars = ft_nbr_size(n);
	v = (unsigned)((n < 0) ? -n : n);
	ret = ft_strnew(num_chars);
	ret[num_chars] = 0;
	if (!v)
		ret[0] = '0';
	else if (neg)
		ret[0] = '-';
	temp = num_chars - 1;
	while (v)
	{
		ret[temp--] = '0' + v % 10;
		v /= 10;
	}
	return (ret);
}
