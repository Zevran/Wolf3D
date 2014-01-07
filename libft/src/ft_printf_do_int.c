/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:55:53 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 16:05:14 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include "libft_converters.h"

int	ft_putnbr_base_d_f(t_flag *flag, va_list ap)
{
	int	len;
	int	nb;
	int	spaces;

	nb = va_arg(ap, long int);
	len = ft_nbrlen(nb, 10);
	spaces = ft_get_nbr_spaces(flag, nb) - len;
	len += ft_print_default_spaces(flag, spaces);
	len += ft_print_blank_space(flag, nb);
	len += ft_print_sign(flag, nb);
	ft_putnbr_base_s(flag->fd, (int) nb, 10, 0);
	len += ft_print_left_spaces(flag, spaces);
	return (len);
}

int	ft_putnbr_base_u_f(t_flag *flag, va_list ap)
{
	int		len;
	t_uint	nb;
	int		spaces;

	nb = va_arg(ap, t_uint);
	len = ft_nbrlen((t_uint) nb, 10);
	spaces = ft_get_nbr_spaces(flag, nb) - len;
	len += ft_print_default_spaces(flag, spaces);
	len += ft_print_blank_space(flag, nb);
	len += ft_print_sign(flag, nb);
	ft_putnbr_base_u(flag->fd, (t_uint) nb, 10, 0);
	len += ft_print_left_spaces(flag, spaces);
	return (len);
}
