/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:33:03 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/20 05:08:26 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H

# include <stdlib.h>
# include "libft_config.h"

/*
** Checks if two memory regions overlap
** Returns 1 if a is inside b
*/

int		ft_memoverlap(void *a, const void *b, size_t count);
void	*ft_memalloc(size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memrealloc(void *buf, size_t size);
void	ft_memdel(void **ap);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *b, size_t len);


#endif /* !LIBFT_MEMORY_H */
