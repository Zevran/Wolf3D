/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_pointers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 03:00:29 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 15:53:22 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include "libft_converters.h"

int	ft_putaddr_f(t_flag *flag, va_list ap)
{
	int		spaces;
	int		len;
	void	*nbr;

	nbr = va_arg(ap, void *);
	len = ft_nbrlen_u((long	unsigned int) nbr, 16);
	spaces = ft_get_nbr_spaces(flag, -1) - len;
	len += ft_print_default_spaces(flag, spaces);
	ft_putstr_fd("0x", flag->fd);
	ft_putnbr_base_u(flag->fd, (long unsigned int) nbr, 16, 0);
	len += ft_print_left_spaces(flag, spaces);
	return (len + 2);
}
