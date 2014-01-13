/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:48:23 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/08 19:44:24 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>

t_wolf	*ft_wolf3d_init(t_wolf *wolf, char *argv[])
{
	wolf->width = 1000;
	wolf->height = 625;
	wolf->mlx = mlx_init();
	wolf->window = mlx_new_window(wolf->mlx, wolf->width, wolf->height,
								  "WOLF3D");
	wolf->image = mlx_new_image(wolf->mlx, wolf->width, wolf->height);
	wolf->map = ft_get_map(wolf->map, argv[1]);
	return (wolf);
}

