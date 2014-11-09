/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 08:10:08 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/12 15:04:48 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <libft_printf.h>

static int	od_error(int code, char *dirname, char *message, char *func)
{
	if (errno == code)
	{
		ft_error("%s: %s: %s\n", func, dirname, message);
		return (errno);
	}
	return (0);
}

static int	od_part1(char *dirname, char *func)
{
	if (od_error(EACCES, dirname, "permission denied.", func))
		return (EACCES);
	else if (od_error(ELOOP, dirname, "loop detected in symbolic link.", func))
		return (ELOOP);
	else if (od_error(EINVAL, dirname,
			"the byte file system pathname starts with "
			"/""/, which is not allowed.", func))
		return (EINVAL);
	else if (od_error(EMFILE, dirname,
			"process has too many file descriptors open.",
			func))
		return (EMFILE);
	else if (od_error(ENAMETOOLONG, dirname,
			"name longer than 'PATH_MAX'.", func))
		return (ENAMETOOLONG);
	return (0);
}

static int	od_part2(char *dirname, char *func)
{
	if (od_error(ENFILE, dirname, "too many files opened by the system.", func))
		return (ENFILE);
	else if (od_error(ENOENT, dirname, "loop detected in symbolic link.", func))
		return (ENOENT);
	else if (od_error(ENOTDIR, dirname,
			"a component of the path is not a directory.", func))
		return (ENOTDIR);
	else
	{
		ft_error("%s: %s: unknown error.\n", func, dirname);
		return (errno);
	}
	return (0);
}

DIR			*ft_opendir(char *dirname)
{
	DIR		*handle;

	handle = opendir(dirname);
	if (!handle)
	{
		if (!od_part1(dirname, (char*)__FUNCTION__))
			od_part2(dirname, (char*)__FUNCTION__);
	}
	return (handle);
}
