/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 14:34:57 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 15:54:14 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_print_sign(t_flag *flag, int nb)
{
	if (flag->pos_sign && nb >= 0)
	{
		ft_putchar_fd('+', flag->fd);
		return (1);
	}
	return (0);
}

int	ft_print_blank_space(t_flag *flag, int nb)
{
	if (flag->blank_spaces && nb >= 0)
	{
		ft_putspaces(flag->fd, 1, SPACE(flag->zero_spaces));
		return (1);
	}
	return (0);
}

int	ft_print_default_spaces(t_flag *flag, int spaces)
{
	if (spaces > 0 && (!flag->left_align))
	{
		ft_putspaces(flag->fd, spaces, SPACE(flag->zero_spaces));
		return (spaces);
	}
	return (0);
}

int	ft_print_left_spaces(t_flag *flag, int spaces)
{
	if (spaces > 0 && flag->left_align)
	{
		ft_putspaces(flag->fd, spaces, SPACE(flag->zero_spaces));
		return (spaces);
	}
	return (0);
}

int	ft_get_nbr_spaces(t_flag *flag, int nbr)
{
	int	i;

	i = 0;
	if (flag->length)
	{
		i 	= flag->length - flag->blank_spaces;
		if (nbr >= 0)
			i += flag->pos_sign;
	}
	return (i);
}

