/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_unused.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 14:31:10 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 16:05:27 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_putunused_Z_f(t_flag *flag, va_list ap)
{
	int	len;
	int	spaces;

	len = 1;
	(void)ap;
	spaces = ft_get_nbr_spaces(flag, -1) - 1;
	len += ft_print_default_spaces(flag, spaces);
	ft_putchar('Z');
	len += ft_print_left_spaces(flag, spaces);
	return (len);
}

int	ft_putunused_k_f(t_flag *flag, va_list ap)
{
	int	len;
	int	spaces;

	len = 1;
	(void)ap;
	spaces = ft_get_nbr_spaces(flag, -1) - 1;
	len += ft_print_default_spaces(flag, spaces);
	ft_putchar('k');
	len += ft_print_left_spaces(flag, spaces);
	return (len);
}
