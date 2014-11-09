/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 08:27:50 by greyrol           #+#    #+#             */
/*   Updated: 2013/12/29 08:29:38 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <libft_file.h>
#include <libft_printf.h>

t_bool	ft_file_executable(const char *path)
{
	return (ft_file_access(path, X_OK));
}

t_bool	ft_file_access(const char *path, int access_mode)
{
	if (access(path, access_mode))
	{
		return (FALSE);
	}
	return (TRUE);
}
