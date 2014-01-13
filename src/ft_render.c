/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 15:39:46 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/09 23:28:59 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>

void	ft_init_ray(t_wolf *wolf, int x)
{
	CAM_X = (2 * x / wolf->width) - 1;
	RAY_P_X = wolf->map->POS_X;
	RAY_P_Y = wolf->map->POS_Y;
	RAY_W_X = WAY_X + PLAN_X * CAM_X;
	RAY_W_Y = WAY_Y + PLAN_Y * CAM_X;
}

void	ft_render(t_wolf *wolf)
{
	int x;
	int	y;
	int	map[2];
	int	sideDist[2];
	int	deltaDist[2];
	int	step[2];
	int	collision;
	int	orientation;
	int	trueWallDist;

	x = 0;
	y = 0;
	while (x <= wolf->width)
	{
		ft_init_ray(wolf, x);
		map[0] = RAY_P_X;
		map[1] = RAY_P_Y;
		if (RAY_W_X < 0)
		{
			step[0] = -1;
			sideDist[0] = (RAY_P_X - map[0]);
		}
		else
		{
			step[0] = 1;
			sideDist[0] = (map[0] + 1 - RAY_P_X) * deltaDist[0];
		}
		if (RAY_W_Y < 0)
		{
			step[1] = -1;
			sideDist[1] = (RAY_P_Y - map[1]);
		}
		else
		{
			step[1] = 1;
			sideDist[1] = (map[1] + 1 - RAY_P_Y) * deltaDist[1];
		}
		while (!collision)
		{
			if (sideDist[0] < sideDist[1])
			{
				sideDist[0] += deltaDist[0];
				map[0] += step[0];
				orientation = 0;
			}
			else
			{
				sideDist[1] += deltaDist[1];
				map[1] += step[1];
				orientation = 1;
			}
			if (wolf->map->grid[map[0]][map[1]] > 0)
				collision = 1;
		}
		if (orientation)
			trueWallDist = abs((map[0] - RAY_P_X + (1 - step[0]) / 2) / RAY_W_X);
		else
			trueWallDist = abs((map[1] - RAY_P_Y + (1 - step[1]) / 2) / RAY_W_Y);
	}

}
