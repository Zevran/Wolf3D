/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:30:15 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:56:42 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *str)
{
	return (ft_putstr_fd(str, 1));
}

int		ft_putstr_u(const unsigned char *s)
{
	return (ft_putstr_fd((char *) s, 1));
}

void	ft_putspaces(int fd, int nbr, char type)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		ft_putchar_fd((const char) &type, fd);
		i++;
	}
}
