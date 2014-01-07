/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 14:43:53 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:56:24 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_converters.h"

int		get_flag_precision(char *format, t_flag *flag, int index)
{
	int	len;

	len = 0;
	flag->precision = ft_atoi(&format[index]);
	len = ft_nbrlen(flag->precision, 10) - 1;
	return (len);
}

int		get_flag_length(char *format, t_flag *flag, int index)
{
	int	len;

	len = 0;
	flag->length = ft_atoi(&format[index]);
	len = ft_nbrlen(flag->length, 10) - 1;
	return (len);
}

t_flag*	ft_init_format(int fd, t_flag *flag)
{
	flag = (t_flag*) malloc(sizeof(t_flag));
	flag->fd = fd;
	flag->left_align = 0;
	flag->pos_sign = 0;
	flag->zero_spaces = 0;
	flag->blank_spaces = 0;
	flag->length = 0;
	flag->precision = 0;
	return (flag);
}

int		ft_sub_format(char *format, va_list ap, t_flag *flag, int *i)
{
	int	has_flag;
	int	(*function[15])(t_flag *flag, va_list ap);

	has_flag = 0;
	init_(function);
	while (format[(*i)++] && (has_flag == 0))
	{
		if (format[*i] == '#')
			flag->convert = 1;
		else if (format[*i] == '-')
			flag->left_align = 1;
		else if (format[*i] == '+')
			flag->pos_sign = 1;
		else if (format[*i] == '0')
			flag->zero_spaces = 1;
		else if (format[*i] == ' ')
			flag->blank_spaces = 1;
		else if (ft_isdigit(format[*i]))
			*i += get_flag_length(format, flag, *i);
		else if (format[*i] == '.' && ft_isdigit(format[*i]))
			*i += get_flag_precision(format, flag, *i);
		else if (get_flag(format[*i]) != -1)
			has_flag = function[get_flag(format[*i])](flag, ap);
	}
	return (has_flag);
}

int		ft_format(int fd, char *format, va_list ap, int *index)
{
	int		i;
	int		has_flag;
	t_flag	*flag;

	i = 0;
	flag = NULL;
	flag = ft_init_format(fd, flag);
	has_flag = ft_sub_format(format, ap, flag, &i);
	if (i > 1)
		*index += i;
	free(flag);
	return (has_flag - i);
}

