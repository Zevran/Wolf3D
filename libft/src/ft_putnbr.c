/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:34:45 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 16:05:55 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(int num)
{
	return (ft_putnbr_fd(num, 1));
}

void	ft_putnbr_base_s(int fd, long nbr, int base, int caps)
{
	char	*s_base;

	s_base = NULL;
	if (base == 2)
		s_base = "01";
	else if (base == 10)
		s_base = "0123456789";
	else if (base == 8)
		s_base = "01234567";
	else if (base == 16 && (!caps))
		s_base = "0123456789abcdef";
	else if (base == 16 && caps)
		s_base = "0123456789ABCDEF";
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_base_u(fd, -nbr, base, caps);
	}
	if (nbr >= (long) ft_strlen(s_base))
		ft_putnbr_base_u(fd, nbr / ft_strlen(s_base), base, caps);
	if (nbr >= 0)
		ft_putchar_fd(s_base[nbr % ft_strlen(s_base)], fd);
}

void	ft_putnbr_base_u(int fd, long unsigned int nbr, int base, int caps)
{
	char	*s_base;

	s_base = NULL;
	if (base == 2)
		s_base = "01";
	else if (base == 10)
		s_base = "0123456789";
	else if (base == 8)
		s_base = "01234567";
	else if (base == 16 && (!caps))
		s_base = "0123456789abcdef";
	else if (base == 16 && caps)
		s_base = "0123456789ABCDEF";
	if (nbr >= ft_strlen(s_base))
		ft_putnbr_base_u(fd, nbr / ft_strlen(s_base), base, caps);
	ft_putchar_fd(s_base[nbr % ft_strlen(s_base)], fd);
}
