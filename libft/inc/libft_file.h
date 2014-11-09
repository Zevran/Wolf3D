/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:00:47 by greyrol           #+#    #+#             */
/*   Updated: 2014/02/16 11:48:25 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FILE_H
# define LIBFT_FILE_H

# include <sys/dir.h>
# include <sys/stat.h>
# include <libft_config.h>

# define FT_PATH_SEPARATOR "/"

typedef struct		s_file
{
	char			*name;
	struct stat		infos;
}					t_file;

/*
** int					lstat(const char *name, struct stat *buf);
*/
typedef void		(*t_search_mismatch)(const char *, const char *);
typedef void		(*t_search_match)(const char *);

typedef struct		s_search_params
{
	char				dir[1042];
	int					access_mode;
	t_bool				recursive;
	t_search_match		match;
	t_search_mismatch	mismatch;
}					t_search_params;

t_search_params		*ft_search_set_params(t_search_params *p, const char *dir,
										int access,
										t_bool recursive);
char				*ft_search_file(const char *pattern,
									t_search_params *params,
									t_bool print_errors);
DIR					*ft_opendir(char *dirname);
struct dirent		*ft_readdir(DIR *handle);
char				*ft_file_basename(const char *path, char **buffer,
									size_t num);
t_file				*ft_file_infos(const char *path, t_file **file);
void				ft_file_reset(t_file *file);
void				ft_file_del(t_file **file);
t_bool				ft_file_executable(const char *path);
t_bool				ft_file_access(const char *path, int access_mode);

char				*ft_path_add(const char *a, const char *b, char **buffer);

#endif
