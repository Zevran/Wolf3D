/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:00:47 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/05 15:06:19 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FILE_H
# define LIBFT_FILE_H

# include <unistd.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include "libft_config.h"

# define FT_PATH_SEPARATOR "/"

typedef struct	dirent	t_dirent;
typedef struct	stat	t_stat;

typedef struct		s_file
{
	char			*name;
	struct stat		infos;
}					t_file;

typedef struct		s_search_file
{
	char			*name;
	char			*dirname;
	char			*path;
	int				access_mode;
	t_dirent		*ent;
	t_stat			*stat;
}					t_search_file;

typedef void	(*t_search_mismatch)(const char *, const char *);
typedef void	(*t_search_match)(const char *);

char			*ft_search_file(t_search_file *file, t_bool print_errors,
								t_search_match match,
								t_search_mismatch mmatch);
char			*ft_search_file_part(t_search_file *file, t_bool print_errors,
							 t_search_match match,
							 t_search_mismatch mmatch);
DIR				*ft_opendir(char *dirname);
t_dirent		*ft_readdir(DIR *handle);
char			*ft_file_basename(const char *path, char **buffer, size_t num);
t_file			*ft_file_infos(const char *path, t_file **file);
void			ft_file_reset(t_file *file);
void			ft_file_del(t_file **file);
t_bool			ft_file_executable(const char *path);

char			*ft_path_add(const char *a, const char *b, char **buffer);

#endif /* !LIBFT_FILE_H */

