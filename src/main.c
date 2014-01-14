/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:12:13 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/13 18:25:02 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <libft_printf.h>

static void	usage()
{
	ft_printf("usage: ./wolf3d map.w3d\n");
}

int			main(int argc, char *argv[])
{
	t_wolf	*wolf;

	wolf = (t_wolf *) malloc(sizeof(t_wolf));
	if (argc > 1)
	{
		wolf = ft_wolf3d_init(wolf, argv);
	}
	else
		usage();
	return (0);
}
