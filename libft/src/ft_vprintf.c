/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 15:15:09 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/12 15:15:22 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>

int				ft_vprintf(const char *fmt, va_list args)
{
	return (ft_vfprintf(1, fmt, args));
}
