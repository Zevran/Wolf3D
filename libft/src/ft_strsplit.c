/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 20:45:01 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:59:25 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_count_words(char const *s, char sep)
{
	size_t		ret;

	ret = 0;
	while (s && *s)
	{
		if (*s == sep)
			ret++;
		while (*s == sep)
			s++;
		s++;
	}
	return (ret);
}

size_t			ft_strlen_ptr(char const *start, char const *end)
{
	if (!end)
		return (ft_strlen(start));
	return (((unsigned char *) end - (unsigned char *) start));
}

static	char	*trim_chars(char *ptr, char c)
{
	while (ptr && *ptr == c)
		ptr++;
	return (ptr);
}

static	char	*trim_word(char *ptr, char c)
{
	while (ptr && (*ptr != c) && *ptr)
		ptr++;
	return (ptr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*ptr;
	char	*orig;
	char	**ret;
	char	**p_ret;
	size_t	len;

	len = ft_count_words(s, c);
	ret = (char **) ft_memalloc(sizeof(char *) * (len + 1));
	ptr = (char *) s;
	p_ret = ret;
	while (ptr && *ptr)
	{
		ptr = trim_chars(ptr, c);
		orig = ptr;
		ptr = trim_word(ptr, c);
		len = ft_strlen_ptr(orig, ptr);
		if (orig && p_ret && *orig)
			*p_ret++ = ft_strsub(orig, 0, len);
		if (!*ptr)
			break ;
		ptr++;
	}
	*p_ret = NULL;
	return (ret);
}
