/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:54:07 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:55:13 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include "libft_converters.h"

int	ft_putchar_f(t_flag *flag, va_list ap)
{
	int		len;
	int		spaces;
	char	c;

	len = 1;
	c = va_arg(ap, int);
	spaces = ft_get_nbr_spaces(flag, -1) - 1;
	len += ft_print_default_spaces(flag, spaces);
	ft_putchar_fd(c, flag->fd);
	len += ft_print_left_spaces(flag, spaces);
	return (len);
}

int	ft_putmodulo(t_flag *flag, va_list ap)
{
	int	len;
	int	spaces;

	len = 1;
	(void)ap;
	spaces = ft_get_nbr_spaces(flag, -1) - 1;
	len += ft_print_default_spaces(flag, spaces);
	ft_putchar_fd('%', flag->fd);
	len += ft_print_left_spaces(flag, spaces);
	return (len);
}

int	ft_putstr_f(t_flag *flag, va_list ap)
{
	int		spaces;
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if (str)
	{
		spaces = ft_get_nbr_spaces(flag, -1) - len;
		len += ft_print_default_spaces(flag, spaces);
		ft_putstr_fd(str, flag->fd);
		len += ft_print_left_spaces(flag, spaces);
		return (len);
	}
	ft_putstr_fd("(null)", flag->fd);
	return (6);
}

int	ft_putstr_u_f(t_flag *flag, va_list ap)
{
	int			spaces;
	t_uchar		*str;
	int			len;

	str = va_arg(ap, t_uchar *);
	len = ft_strlen((char *) str);
	spaces = ft_get_nbr_spaces(flag, -1) - len;
	len += ft_print_default_spaces(flag, spaces);
	ft_putstr_fd((char *) str, flag->fd);
	len += ft_print_left_spaces(flag, spaces);
	return (len);
}

