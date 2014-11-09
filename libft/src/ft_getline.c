/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:04:57 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/19 15:10:25 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_io.h>
#include <libft_memory.h>
#include <libft_string.h>
#include <unistd.h>

static int	ft_getline_handle_buffer(char **buf, char *sbuf, int *total,
									int bytes_read)
{
	char		*pos;

	*buf = ft_realloc(*buf, *total + bytes_read + 1);
	if (!*buf)
		return (-1);
	ft_strncpy(*buf + *total, sbuf, bytes_read);
	if ((pos = ft_strchr(*buf, '\n')))
	{
		*pos++ = '\0';
		ft_strncpy(sbuf, pos, FT_BUF_MAX);
		while (*pos)
			*pos++ = '\0';
		return (1);
	}
	return (0);
}

static int	ft_getline_pass(int fd, char **buf, int *total)
{
	static char	sbuf[FT_BUF_MAX] = {0};
	int			bytes_read;

	if (sbuf[0])
	{
		if (ft_getline_handle_buffer(buf, sbuf, total, FT_BUF_MAX) > 0)
			return (1);
	}
	bytes_read = read(fd, sbuf, FT_BUF_MAX);
	if (bytes_read > 0)
	{
		if (ft_getline_handle_buffer(buf, sbuf, total, bytes_read) > 0)
			return (1);
		else
		{
			*total += bytes_read;
			return (ft_getline_pass(fd, buf, total));
		}
		return (0);
	}
	*total += bytes_read;
	return (-1);
}

int			ft_getline(int fd, char **buf)
{
	int			total;

	total = 0;
	return (ft_getline_pass(fd, buf, &total));
}
