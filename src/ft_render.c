/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 15:39:46 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/14 22:40:55 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_get_distance(t_wolf *wolf)
{
	if (RAY_W_X < 0)
	{
		wolf->step[0] = -1;
		wolf->sDist[0] = (RAY_P_X - wolf->internMap[0]) * wolf->dDist[0];
	}
	else
	{
		wolf->step[0] = 1;
		wolf->sDist[0] = (wolf->internMap[0] + 1.0 - RAY_P_X) * wolf->dDist[0];
	}
	if (RAY_W_Y < 0)
	{
		wolf->step[1] = -1;
		wolf->sDist[1] = (RAY_P_Y - wolf->internMap[1]) * wolf->dDist[1];
	}
	else
	{
		wolf->step[1] = 1;
		wolf->sDist[1] = (wolf->internMap[1] + 1.0 - RAY_P_Y) * wolf->dDist[1];
	}
}

static void	ft_dig_diff_ana(t_wolf *wolf)
{
	while (wolf->collision == 0)
	{
		if (wolf->sDist[0] < wolf->sDist[1])
		{
			wolf->sDist[0] += wolf->dDist[0];
			wolf->internMap[0] += wolf->step[0];
			wolf->orientation = 0;
		}
		else
		{
			wolf->sDist[1] += wolf->dDist[1];
			wolf->internMap[1] += wolf->step[1];
			wolf->orientation = 1;
		}
		if (wolf->map->grid[wolf->internMap[0]][wolf->internMap[1]] > 0)
			wolf->collision = 1;
	}
}

static void	ft_fish_eyes(t_wolf *wolf)
{
	if (!wolf->orientation)
		wolf->trueWallDist = abs_f((wolf->internMap[0] - RAY_P_X
									+ (1 - wolf->step[0]) / 2) / RAY_W_X);
	else
		wolf->trueWallDist = abs_f((wolf->internMap[1] - RAY_P_Y
									+ (1 - wolf->step[1]) / 2) / RAY_W_Y);
}

static void	ft_get_wall_high(t_wolf *wolf, int x)
{
	float	lineHigh;
	float	y[2];
	int		color;

	lineHigh = abs(wolf->height / wolf->trueWallDist);
	y[0] = -lineHigh / 2 + wolf->height / 2;
	if (y[0] < 0)
		y[0] = 0;
	y[1] = lineHigh / 2 + wolf->height / 2 / wolf->trueWallDist / 2;
	if (y[1] >= wolf->height)
		y[1] = wolf->height;
	color = get_color(wolf);
	ft_env_floor(wolf, y[1], x);
	ft_env_sky(wolf, y[0], x);
	ft_env_line(wolf, x, y, color);
}

void		ft_render(t_wolf *wolf)
{
	int	x;

	x = 0;
	wolf = ft_init_internal_env(wolf);
	while (x < wolf->width)
	{
		wolf = ft_init_internal_ray(wolf, x);
		wolf = ft_init_internal_map(wolf);
		ft_get_distance(wolf);
		ft_dig_diff_ana(wolf);
		ft_fish_eyes(wolf);
		ft_get_wall_high(wolf, x);
		x++;
	}
}
