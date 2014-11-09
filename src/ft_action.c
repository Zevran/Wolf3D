/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:36:36 by greyrol           #+#    #+#             */
/*   Updated: 2014/11/09 14:36:37 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	move_cam(float dirx, float diry, t_wolf *wolf)
{
	if (wolf->map[(int)(POS_X + dirx * 0.10)][(int)POS_Y] < 1)
		POS_X += dirx * 0.05;
	if (wolf->map[(int)POS_X][(int)(POS_Y + diry * 0.10)] < 1)
		POS_Y += diry * 0.05;
}

void	turn_cam(float angle, float oldplanex, float olddirx, t_wolf *wolf)
{
	DIR_X = DIR_X * cos(angle) - DIR_Y * sin(angle);
	DIR_Y = olddirx * sin(angle) + DIR_Y * cos(angle);
	PLN_X = PLN_X * cos(angle) - PLN_Y * sin(angle);
	PLN_Y = oldplanex * sin(angle) + PLN_Y * cos(angle);
}
