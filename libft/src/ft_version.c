/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_version.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 06:15:05 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/28 06:22:41 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_version.h"
#include "libft_string.h"
#include "libft_converters.h"

static const unsigned int g_version_major = __VERSION_MAJOR;
static const unsigned int g_version_minor = __VERSION_MINOR;
static const unsigned int g_version_build = __VERSION_BUILD;
static const unsigned int g_version_rev = __VERSION_REV;

int				ft_version_major(void)
{
	return (g_version_major);
}

int				ft_version_minor(void)
{
	return (g_version_minor);
}

int				ft_version_build(void)
{
	return (g_version_build);
}

int				ft_version_rev(void)
{
	return (g_version_rev);
}

char			*ft_version_string(void)
{
	static char	buf[255];

	ft_strncpy(buf, ft_ntoa(g_version_major, 10), 255);
	ft_strncat(buf, ".", 255);
	ft_strncat(buf, ft_ntoa(g_version_minor, 10), 255);
	ft_strncat(buf, ".", 255);
	ft_strncat(buf, ft_ntoa(g_version_build, 10), 255);
	ft_strncat(buf, ".", 255);
	ft_strncat(buf, ft_ntoa(g_version_rev, 10), 255);
	return (buf);
}
