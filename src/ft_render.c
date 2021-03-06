/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:13:53 by greyrol           #+#    #+#             */
/*   Updated: 2014/11/09 15:13:54 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

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

	linehigh = fabs((wolf->height) / wolf->true_wall_dist);
	y[0] = -linehigh / 2 + wolf->height / 2 + wolf->up;
	if (y[0] < 0)
		y[0] = 0;
	y[1] = linehigh / 2 + wolf->height / 2 + wolf->up / wolf->true_wall_dist
			/ 2;
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
	ft_fps_box(wolf);
	ft_draw_keys(wolf);
}
