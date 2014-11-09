/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:49:31 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:18:41 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_converters.h>
#include <math.h>

t_float					ft_create_float(double val, int precision)
{
	t_float				r;

	r.value = val;
	r.sign = 1;
	r.precision = precision;
	if (val <= (-FLOAT_TOLERANCE))
	{
		r.value *= -1.0;
		r.sign = -1;
	}
	r.parts[0] = r.value;
	r.parts[1] -= r.value - (double)r.parts[0];
	return (r);
}

void					ft_extract_whole(t_float *f, int dig_len, char **ptr)
{
	long				i;
	long				tmp;

	i = dig_len;
	while (i > 0)
	{
		tmp = (f->parts[0] / pow(10, i - 1));
		**ptr = '0' + tmp;
		*ptr += 1;
		*((long*)&f->parts[0]) %= tmp;
		i--;
	}
}

void					ft_extract_decimal(t_float *f, char **ptr)
{
	long				i;
	double				d;

	d = f->parts[1];
	i = 0;
	while (i < f->precision)
	{
		d *= 10.0;
		**ptr = '0' + d;
		*ptr += 1;
		d -= d;
		i++;
	}
}

char					*ft_ftoa(double n, int precision)
{
	static char			buf[FLOAT_MAX_LENGTH] = {0};
	char				*bufptr;
	long				i;
	t_float				f;
	long				tmp;

	bufptr = buf;
	i = precision;
	f = ft_create_float(n, precision);
	while (i > -1)
	{
		tmp = f.parts[0] / pow(10, i);
		if (tmp > 0)
			break ;
		i--;
	}
	ft_extract_whole(&f, i + 1, &bufptr);
	*bufptr++ = '.';
	ft_extract_decimal(&f, &bufptr);
	*bufptr = '\0';
	return (buf);
}
