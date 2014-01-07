/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:59:02 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 15:52:59 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include "libft_converters.h"

int	ft_putnbr_base_o_f(t_flag *flag, va_list ap)
{
	int		len;
	t_uint	nb;
	int		spaces;

	nb = va_arg(ap, t_uint);
	len = ft_nbrlen((t_uint) nb, 8);
	spaces = ft_get_nbr_spaces(flag, nb) - len;
	len += ft_print_default_spaces(flag, spaces);
	len += ft_print_blank_space(flag, nb);
	len += ft_print_sign(flag, nb);
	len += ft_convert(flag, "0");
	ft_putnbr_base_u(flag->fd, (t_uint) nb, 8, 0);
	len += ft_print_left_spaces(flag, spaces);
	return (len);
}

int	ft_putnbr_base_x_f(t_flag *flag, va_list ap)
{
	int		len;
	t_uint	nb;
	int		spaces;

	nb = va_arg(ap, t_uint);
	len = ft_nbrlen(nb, 16);
	spaces = ft_get_nbr_spaces(flag, nb) - len;
	len += ft_print_default_spaces(flag, spaces);
	len += ft_print_blank_space(flag, nb);
	len += ft_print_sign(flag, nb);
	len += ft_convert(flag, "0x");
	ft_putnbr_base_u(flag->fd, (long) nb, 16, 0);
	len += ft_print_left_spaces(flag, spaces);
	return (len);
}

int	ft_putnbr_base_X_f(t_flag *flag, va_list ap)
{
	int		len;
	t_uint	nb;
	int		spaces;

	nb = va_arg(ap, t_uint);
	len = ft_nbrlen(nb, 16);
	spaces = ft_get_nbr_spaces(flag, nb) - len;
	len += ft_print_default_spaces(flag, spaces);
	len += ft_print_blank_space(flag, nb);
	len += ft_print_sign(flag, nb);
	len += ft_convert(flag, "0x");
	ft_putnbr_base_u(flag->fd, (long) nb, 16, 1);
	len += ft_print_left_spaces(flag, spaces);
	return (len);
}

int	ft_putnbr_base_b_f(t_flag *flag, va_list ap)
{
	int		len;
	t_uint	nb;
	int		spaces;

	nb = va_arg(ap, t_uint);
	len = ft_nbrlen(nb, 2);
	spaces = ft_get_nbr_spaces(flag, nb);
	len += ft_print_default_spaces(flag, spaces);
	len += ft_print_blank_space(flag, nb);
	len += ft_print_sign(flag, nb);
	ft_putnbr_base_u(flag->fd, (long) nb, 2, 0);
	len += ft_print_left_spaces(flag, spaces);
	return (len);
}
