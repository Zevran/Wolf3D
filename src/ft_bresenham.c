/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 15:25:06 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/09 20:18:16 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>
#include <math.h>

static void	ft_bsh_part_1(int *x, int *y, t_bsh *bsh)
{
	bsh->xi = ((y[0] > x[0]) ? 1  : -1);
	bsh->dy = y[1] - x[1];
	bsh->dx = abs(y[0] - x[0]);
	bsh->d = 2 * bsh->dx - bsh->dy;
	bsh->ai = 2 * (bsh->dx - bsh->dy);
	bsh->bi = 2 * bsh->dx;
	bsh->x = x[0];
	bsh->y = x[1];
}

static void	ft_bsh_part_2(t_wolf *wolf, int *x, int *y, t_bsh *bsh)
{
	bsh->y += x[1];
	while (bsh->y <= y[1])
	{
		if (bsh->d >= 0)
		{
			bsh->x += bsh->xi;
			bsh->d += bsh->ai;
		}
		else
			bsh->d += bsh->bi;
		ft_put_pixel(wolf, bsh->x, bsh->y, bsh->color);
		bsh->y++;
	}
}

static void	ft_bsh_part_3(int *x, int *y, t_bsh *bsh)
{
	bsh->yi = ((y[1] > x[1]) ? 1 : -1);
	bsh->dx = y[0] - x[0];
	bsh->dy = abs(y[1] - x[1]);
	bsh->d = 2 * bsh->dy - bsh->dx;
	bsh->ai = 2 * (bsh->dy - bsh->dx);
	bsh->bi = 2 * bsh->dy;
	bsh->x = x[0];
	bsh->y = x[1];
}

static void	ft_bsh_part_4(t_wolf *wolf, int *x, int *y, t_bsh *bsh)
{
	bsh->x += x[0];
	while (bsh->x <= y[0])
	{
		if (bsh->d >= 0)
		{
			bsh->y += bsh->yi;
			bsh->d += bsh->ai;
		}
		else
			bsh->d += bsh->bi;
		ft_put_pixel(wolf, bsh->x, bsh->y, bsh->color);
		bsh->x++;
	}
}

void	ft_bsh_draw(t_wolf *wolf, int *x, int *y)
{
	t_bsh	*bsh;
	if (abs(y[0] - x[0]) < abs(y[1] - x[1]))
	{
		if (x[0] > y[1])
		{
			ft_swap(&x[0], &y[0]);
			ft_swap(&x[1], &y[1]);
		}
		ft_bsh_part_1(x, y, bsh);
		ft_bsh_part_2(wolf, x, y, bsh);
	}
	else
	{
		if (x[0] > y[0])
		{
			ft_swap(&x[0], &y[0]);
			ft_swap(&x[1], &y[1]);
		}
		ft_bsh_part_3(x, y, bsh);
		ft_bsh_part_4(wolf, x, y, bsh);
	}
}
