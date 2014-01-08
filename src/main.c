/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:12:13 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/08 16:13:39 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <libft_printf.h>
#include <mlx.h>

void	usage()
{
	ft_printf("usage: ./wolf3d map.w3d\n");
}

int		main(int argc, char *argv[])
{
	t_wolf	*wolf;

	wolf = (t_wolf *) malloc(sizeof(t_wolf));
	if (argc > 1)
	{
		wolf->width = 1000;
		wolf->height = 625;
		wolf->mlx = mlx_init();
		wolf->window = mlx_new_window(wolf->mlx, wolf->width, wolf->height, "WOLF3D");
		wolf->image = mlx_new_image(wolf->mlx, wolf->width, wolf->height);
		wolf->map = ft_get_map(wolf->map, argv[1]);
	}
	else
		usage();
	return (0);
}
