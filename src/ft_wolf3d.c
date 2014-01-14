/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:48:23 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/14 22:14:41 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <libft_printf.h>

t_wolf	*ft_wolf3d_init(t_wolf *wolf, char *argv[])
{
	wolf->width = 1000;
	wolf->height = 625;
	wolf->mlx = mlx_init();
	wolf->window = mlx_new_window(wolf->mlx, wolf->width, wolf->height,
								  "WOLF3D");
	wolf->image = mlx_new_image(wolf->mlx, wolf->width, wolf->height);
	wolf->map = ft_get_map(wolf->map, argv[1]);
	wolf->data = mlx_get_data_addr(wolf->image, &wolf->bpp, &wolf->size_l,
															&wolf->endian);
	ft_render(wolf);
	mlx_put_image_to_window(wolf->mlx, wolf->window, wolf->image, 0, 0);
	sleep(50);
	return (wolf);
}

t_wolf	*ft_init_internal_env(t_wolf *wolf)
{
	wolf->env = (t_env *) malloc(sizeof(t_env));
	WAY_X = -1;
	WAY_Y = 0;
	PLAN_X = 0;
	PLAN_Y = 0.66;
	wolf->map->POS_X = 1.0;
	wolf->map->POS_Y = 10.0;
	return (wolf);
}

t_wolf	*ft_init_internal_map(t_wolf *wolf)
{
	wolf->internMap[0] = RAY_P_X;
	wolf->internMap[1] = RAY_P_Y;
	wolf->dDist[0] = sqrt(1 + (RAY_W_Y * RAY_W_Y) / (RAY_W_X * RAY_W_X));
	wolf->dDist[1] = sqrt(1 + (RAY_W_X * RAY_W_X) / (RAY_W_Y * RAY_W_Y));
	wolf->collision = 0;
	return (wolf);
}

t_wolf	*ft_init_internal_ray(t_wolf *wolf, int x)
{
	CAM_X = ((2 * x) / ((float) wolf->width - 1));
	RAY_P_X = wolf->map->POS_X;
	RAY_P_Y = wolf->map->POS_Y;
	RAY_W_X = WAY_X + PLAN_X * CAM_X;
	RAY_W_Y = WAY_Y + PLAN_Y * CAM_X;
	return (wolf);
}
