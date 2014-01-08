/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:12:13 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/08 15:10:10 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <libft_printf.h>

void	usage()
{
	ft_printf("usage: ./wolf3d map.w3d\n");
}

int		main(int argc, char *argv[])
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (argc > 1)
	{
		map = ft_get_map(map, argv[1]);
	}
	else
		usage();
	return (0);
}
