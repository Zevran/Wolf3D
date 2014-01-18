/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_converters.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 01:30:30 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/18 20:48:48 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CONVERTERS_H
# define LIBFT_CONVERTERS_H

#include <stdlib.h>

char	*ft_itoa(int n);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
size_t	ft_nbrlen(long int nbr, int base);
size_t	ft_nbrlen_u(long unsigned int nbr, int base);
char	*ft_ntoa(unsigned long num, int base);


#endif /* !LIBFT_CONVERTERS_H */
