/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 02:15:22 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/05 14:35:14 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft_config.h"
# include "libft_string.h"

# define SPACE(n) ((n == 1) ? '0' : ' ')

typedef struct	s_flag
{
	int		fd;
	char	range;
	int		convert;
	int		left_align;
	int		pos_sign;
	int		zero_spaces;
	int		blank_spaces;
	int		length;
	int		precision;
}				t_flag;

int		ft_convert(t_flag *flag, char *type);
int		ft_print_sign(t_flag *flag, int nb);
int		ft_print_blank_space(t_flag *flag, int 		nb);
int		ft_print_default_spaces(t_flag *flag, int spaces);
int		ft_print_left_spaces(t_flag *flag, int spaces);
int		ft_get_nbr_spaces(t_flag *flag, int nbr);

int		ft_sub_format(char *format, va_list ap, t_flag *flag, int *index);
int		ft_format(int fd, char *format, va_list ap, int *index);

int		get_flag(char f);
int		print_escaped(int fd, char *str);
void	init_(int (**function)(t_flag *flag, va_list ap));
int		ft_parse(int fd, char *format, va_list ap);
int		ft_printf(char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);
int		ft_error(const char *fmt, ...);

int		ft_putstr_f(t_flag *flag, va_list ap);
int		ft_putchar_f(t_flag *flag, va_list ap);
int		ft_putstr_u_f(t_flag *flag, va_list ap);
int		ft_putnbr_base_d_f(t_flag *flag, va_list ap);
int		ft_putnbr_base_u_f(t_flag *flag, va_list ap);
int		ft_putnbr_base_o_f(t_flag *flag, va_list ap);
int		ft_putnbr_base_x_f(t_flag *flag, va_list ap);
int		ft_putnbr_base_X_f(t_flag *flag, va_list ap);
int		ft_putnbr_base_b_f(t_flag *flag, va_list ap);
int		ft_putaddr_f(t_flag *flag, va_list ap);
int		ft_putmodulo(t_flag *flag, va_list ap);
int		ft_putunused_Z_f(t_flag *flag, va_list ap);
int		ft_putunused_k_f(t_flag *flag, va_list ap);
int		ft_putaddr_f(t_flag *flag, va_list ap);

#endif /* !LIBFT_PRINTF_H */
