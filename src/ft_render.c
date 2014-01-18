/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:56:42 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/18 18:04:55 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>
#include <unistd.h>

void	ft_ray_pos(t_wolf *wolf, int x)
{
	wolf->camx = 2 * x / (float)wolf->width - 1;
	RPS_X = POS_X;
	RPS_Y = POS_Y;
	RDR_X = DIR_X + PLN_X * wolf->camx;
	RDR_Y = DIR_Y + PLN_Y * wolf->camx;
}

void	ft_get_dist(t_wolf *wolf)
{
	if (RDR_X < 0)
	{
		STP_X = -1;
		SDT_X = (RPS_X - MAP_X) * DDT_X;
	}
	else
	{
		STP_X = 1;
		SDT_X = (MAP_X + 1.0 - RPS_X) * DDT_X;
	}
	if (RDR_Y < 0)
	{
		STP_Y = -1;
		SDT_Y = (RPS_Y - MAP_Y) * DDT_Y;
	}
	else
	{
		STP_Y = 1;
		SDT_Y = (MAP_Y + 1.0 - RPS_Y) * DDT_Y;
	}
}

void	ft_get_wall_high(t_wolf *wolf, int x)
{
	float	linehigh;
	float	y[2];
	float	color;

	linehigh = abs((wolf->height) / wolf->trueWallDist);
	y[0] = -linehigh / 2 + wolf->height / 2 + wolf->up;
	if (y[0] < 0)
		y[0] = 0;
	y[1] = linehigh / 2 + wolf->height / 2 + wolf->up / wolf->trueWallDist / 2;
	if (y[1] >= wolf->height)
		y[1] = wolf->height - 1;
	color = (STP_X ? 0x615F5D : 0xB75654);
	if (wolf->orientation == 1)
		color = (STP_Y ? 0x584F4E : 0x353535);
	ft_env_floor(wolf, y[1], x);
	ft_env_sky(wolf, y[0], x);
	ft_env_line(wolf, x, y, color);
}

void	ft_render(t_wolf *wolf)
{
	float	x;

	x = 0;
	while (x < wolf->width)
	{
		ft_ray_pos(wolf, x);
		ft_init_dda(wolf);
		ft_get_dist(wolf);
		ft_dig_diff_ana(wolf);
		ft_correct_feye(wolf);
		ft_get_wall_high(wolf, x);
		x++;
	}
}
