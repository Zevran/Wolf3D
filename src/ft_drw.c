/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 05:32:04 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/18 18:05:45 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void		ft_init_dda(t_wolf *wolf)
{
	MAP_X = RPS_X;
	MAP_Y = RPS_Y;
	DDT_X = sqrt(1 + (RDR_Y * RDR_Y) / (RDR_X * RDR_X));
	DDT_Y = sqrt(1 + (RDR_X * RDR_X) / (RDR_Y * RDR_Y));
	wolf->collision = 0;
}

void		ft_dig_diff_ana(t_wolf *wolf)
{
	while (wolf->collision == 0)
	{
		if (SDT_X < SDT_Y)
		{
			SDT_X += DDT_X;
			MAP_X += STP_X;
			wolf->orientation = 0;
		}
		else
		{
			SDT_Y += DDT_Y;
			MAP_Y += STP_Y;
			wolf->orientation = 1;
		}
		if (wolf->map[MAP_X][MAP_Y] > 0)
			wolf->collision = 1;
	}
}

void		ft_correct_feye(t_wolf *wolf)
{
	if (wolf->orientation == 0)
		wolf->trueWallDist = fabs((MAP_X - RPS_X + (1 - STP_X) / 2) / RDR_X);
	else
		wolf->trueWallDist = fabs((MAP_Y - RPS_Y + (1 - STP_Y) / 2) / RDR_Y);
}

