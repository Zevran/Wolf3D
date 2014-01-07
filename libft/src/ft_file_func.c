/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:06:29 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 15:02:03 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include "libft_memory.h"
#include "libft_file.h"

DIR			*ft_opendir(char *dirname)
{
	DIR	*handle;

	handle = opendir(dirname ? dirname : ".");
	if (!handle)
		ft_error("open: %s: cannot open directory\n", dirname);
	return (handle);
}

t_dirent	*ft_readdir(DIR *handle)
{
	t_dirent	*ent;

	if (!(ent = readdir(handle)))
		return (NULL);
	return (ent);
}

char		*ft_file_basename(const char *path, char **buffer, size_t num)
{
	char		*pos;

	pos = ft_strrchr(path, FT_PATH_SEPARATOR[0]);
	if (!pos)
		return ((char *) path);
	*buffer = NULL;
	return (*buffer = ft_strndup(pos, num));
}

t_file		*ft_file_infos(const char *path, t_file **file)
{
	char	*name;

	if (!*file)
		return (NULL);
	name = NULL;
	ft_file_basename(path, &name, sizeof(t_file));
	(*file)->name = ft_strdup(name);
	lstat(path, &(*file)->infos);
	return (*file);
}

void		ft_file_reset(t_file *file)
{
	if (!file)
		return ;
	if ((file)->name)
		ft_strdel(&(file)->name);
	ft_memset(&file->infos, 0, sizeof(struct stat));
}

