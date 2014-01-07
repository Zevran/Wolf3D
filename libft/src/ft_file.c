/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:06:29 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 14:52:40 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include "libft_memory.h"
#include "libft_file.h"

void	ft_file_del(t_file **file)
{
	if (!*file)
		return ;
	ft_file_reset(*file);
	ft_memdel((void **) file);
}

t_bool	ft_file_executable(const char *path)
{
	if (access(path, X_OK))
		return (FALSE);
	return (TRUE);
}

char	*ft_search_file(t_search_file *file, t_bool print_errors,
						t_search_match match,
						t_search_mismatch mmatch)
{
	DIR				*handle;

	if (!file->dirname || !(handle = opendir(file->dirname)))
		return (NULL);
	while (handle)
	{
		if (!(file->ent = readdir(handle)))
			break ;
		file->path = ft_path_add(file->dirname ? file->dirname : ".",
								 file->ent->d_name,
								 &file->path);
		if (ft_search_file_part(file, print_errors, match, mmatch) == NULL)
			break ;
		else if (ft_search_file_part(file, print_errors, match, mmatch) != NULL)
			return (ft_strdup(file->name));
		else if (S_ISDIR(file->stat->st_mode)
				 && !ft_strequ(file->ent->d_name, ".")
				 && !ft_strequ(file->ent->d_name, ".."))
			return (ft_search_file(file, print_errors, match, mmatch));
	}
	if (handle)
		closedir(handle);
	return (NULL);
}

char	*ft_search_file_part(t_search_file *file, t_bool print_errors,
							 t_search_match match,
							 t_search_mismatch mmatch)
{
	if (!file->path)
	{
		ft_printf("%s: couldnt add two paths:\n\t%s\n\t%s\n", __FUNCTION__,
				  file->dirname, file->ent->d_name);
		return (NULL);
	}
	if (access(file->path, file->access_mode))
		return (NULL);
	else if (lstat(file->path, file->stat) == -1)
	{
		if (print_errors)
			ft_error("stat: %s: cannot stat node\n", file->path);
	}
	else if (S_ISREG(file->stat->st_mode))
	{
		if (ft_strequ(file->name, file->ent->d_name))
		{
			if (match)
				(*match)(file->path);
			return (file->path);
		}
		else if (mmatch)
			(*mmatch)(file->name, file->path);
	}
	return (NULL);
}

char	*ft_path_add(const char *a, const char *b, char **buff)
{
	t_bool		sepra;
	static char	buf[FT_BUF_MAX] = {0};

	(void) buff;
	if (!a)
		return (NULL);
	sepra = (a && ft_strlen(a) && (a[ft_strlen(a) - 1]
				== FT_PATH_SEPARATOR[0]));
	ft_memset(buf, '\0', FT_BUF_MAX);
	ft_strcpy(buf, a);
	if (!sepra)
		ft_strncat(buf, FT_PATH_SEPARATOR, FT_BUF_MAX);
	if (b)
		ft_strncat(buf, b, FT_BUF_MAX);
	return (buf);
}
