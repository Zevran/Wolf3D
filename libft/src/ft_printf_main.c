/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 14:51:31 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:55:50 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int		ft_convert(t_flag *flag, char *type)
{
	if (flag->convert)
	{
		ft_putstr_fd(type, flag->fd);
		return (ft_strlen(type));
	}
	return (0);
}

int		get_flag(char f)
{
	int		i;
	char	*flags;

	i = 0;
	flags = "sScdiuoxXp%bZk";
	while (flags[i] != '\0')
	{
		if (flags[i] == f)
			return (i);
		i++;
	}
	return (-1);
}

void	init_(int (**function)(t_flag *flag, va_list ap))
{
	function[0] = &ft_putstr_f;
	function[1] = &ft_putstr_u_f;
	function[2] = &ft_putchar_f;
	function[3] = &ft_putnbr_base_d_f;
	function[4] = &ft_putnbr_base_d_f;
	function[5] = &ft_putnbr_base_u_f;
	function[6] = &ft_putnbr_base_o_f;
	function[7] = &ft_putnbr_base_x_f;
	function[8] = &ft_putnbr_base_X_f;
	function[9] = &ft_putaddr_f;
	function[10] = &ft_putmodulo;
	function[11] = &ft_putnbr_base_b_f;
	function[12] = &ft_putunused_Z_f;
	function[13] = &ft_putunused_k_f;
}

int		print_escaped(int fd, char *str)
{
		if (*str == 'a')
			ft_putchar_fd('\a', fd);
		else if (*str == 'b')
			ft_putchar_fd('\b', fd);
		else if (*str == 'f')
			ft_putchar_fd('\f', fd);
		else if (*str == 'n')
			ft_putchar_fd('\n', fd);
		else if (*str == 't')
			ft_putchar_fd('\t', fd);
		else if (*str == 'v')
			ft_putchar_fd('\v', fd);
		else if (*str == '%')
			ft_putchar_fd('\\', fd);
		else if (*str == '\\' || *str == '\'')
			ft_putchar_fd(*str, fd);
		else
		{
			ft_putchar_fd('\\', fd);
			ft_putchar_fd(*str, fd);
			return (2);
		}
		return (1);
}

int		ft_parse(int fd, char *format, va_list ap)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\\')
			ft_putstr("backslash\n");
		else if (format[i] == '%')
			total_len += ft_format(fd, &format[i], ap, &i);
		else if (format[i] == '\\')
			i += print_escaped(fd, &format[i + 1]);
		else
			ft_putchar_fd(format[i++], fd);
	}
	return (i + total_len);
}
