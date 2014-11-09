/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_converters.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 01:30:30 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:19:15 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CONVERTERS_H
# define LIBFT_CONVERTERS_H

# include <libft_config.h>
# define FLOAT_MAX_LENGTH	32
# define FLOAT_TOLERANCE	0.000000000001

typedef struct			s_float
{
	double				parts[2];
	int					sign;
	double				value;
	int					precision;
}						t_float;

char					*ft_itoa(int n);
void					ft_extract_whole(t_float *f, int dig_len, char **ptr);
void					ft_extract_decimal(t_float *f, char **ptr);
t_float					ft_create_float(double val, int precision);
char					*ft_ftoa(double n, int precision);
int						ft_atoi(const char *str);
long					ft_atol(const char *str);
size_t					ft_number_length(unsigned long num, int base);
char					*ft_ntoa(unsigned long num, int base);
int						get_float_decimal(float f, int precision);

#endif
