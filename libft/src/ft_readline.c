/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:14:10 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/19 15:49:03 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_char(const int fd, char *c)
{
	static int	i = 0;
	static char	buffer[BUFF_SIZE];
	static int	pb_size = BUFF_SIZE;

	if (i >= pb_size || i == 0)
	{
		i = 0;
		if ((pb_size = read(fd, buffer, BUFF_SIZE)) < 0)
			return (0);
	}
	if (pb_size == 0)
	{
		*c = '\0';
		i = -1;
	}
	else if (buffer[i] == '\n')
		*c = '\0';
	else
		*c = buffer[i];
	i++;
	return (pb_size);
}

int				ft_readline(const int fd, char **line)
{
	int		i;
	int		pb_size;
	char	*str;

	i = 0;
	pb_size = 1;
	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	str = malloc((BUFF_SIZE + 1) * sizeof(*str));
	pb_size = get_char(fd, &str[i]);
	if (pb_size == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (i % BUFF_SIZE == 0)
			str = ft_realloc(str, i + BUFF_SIZE + 1);
		pb_size = get_char(fd, &str[++i]);
	}
	str[++i] = '\0';
	*line = ft_strdup(str);
	free(str);
	return (1);
}
