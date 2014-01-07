/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:15:45 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/18 10:39:09 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtok(char *str, char sep)
{
	char			**ret;
	size_t			id;
	int				pos;
	int				last;
	int				len;

	len = (int) ft_strlen(str);
	id = 0;
	ret = ft_memalloc(sizeof(char *) * FT_TOK_MAX);
	last = pos = 0;
	while ((pos = ft_strfind(str, sep, last)) != -1 && pos < len)
	{
		ret[id] = ft_strnew((pos - 1) - last + 1);
		ft_strncpy(ret[id], str + last, (pos - 1) - last);
		last = pos;
		id++;
	}
	if (len - last > 0)
	{
		ret[id] = ft_strnew(len - last);
		ft_strncpy(ret[id], str + last, len - last);
		id++;
	}
	ret[id] = NULL;
	return (ret);
}
