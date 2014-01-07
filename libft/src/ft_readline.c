/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:14:10 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/18 10:36:58 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_readline(int fd, char **buf)
{
	size_t		i;
	int			bread;

	bread = i = 0;
	*buf = ft_strnew(FT_BUF_MAX + 1);
	while (i < FT_BUF_MAX)
	{
		if ((bread = read(fd, ((*buf) + i), 1)) == -1 || !bread)
		{
			*((*buf) + i) = '\0';
			return (-1);
		}
		if (*((*buf) + i) == '\n' || *((*buf) + i) == '\0')
		{
			*((*buf) + i) = '\0';
			return (1);
		}
		i++;
	}
	*((*buf) + i) = '\0';
	return (0);
}
