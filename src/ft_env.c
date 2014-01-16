/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:00:23 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/16 21:58:37 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

/*
** North : 0xFFFFFF / South : 0xB75654
** West : 0x584F4E / East : 0x353535
*/

float	get_color(t_wolf *wolf)
{
	float	color;

	if (wolf->step[0] == 1)
		color = 0x584F4E;
	else
		color = 0x353535;
	if (wolf->orientation)
	{
		if (wolf->step[1] == 1)
			color = 0x353535;
		else
			color = 0xB75654;
	}
	return (color);
}

void	ft_env_floor(t_wolf *wolf, int end, int x)
{
	int	y;
	int	color[] =
	{
		0x5A, 0x37, 0x09
	};

	y = wolf->height - 1;
	printf("floor end : %d\n", end);
	while (y > end)
		store_pixel(wolf, x, y--, color);
}

void	ft_env_sky(t_wolf *wolf, int end, int x)
{
	int	y;
	int	color[] =
	{
		0x36, 0xBA, 0xE9
	};

	y = 0;
	printf("sky end : %d\n", end);
	while (y < end)
		store_pixel(wolf, x, y++, color);
}

void	ft_env_line(t_wolf *wolf, int x, float *y, int color)
{
	int		tab[3];

	tab[0] = color % 65536;
	color -= tab[0] * 65536;
	tab[1] = color % 256;
	color -= tab[1] * 256;
	tab[2] = color;
	if (y[0] > y[1])
	{
		while (y[1] < y[0])
			store_pixel(wolf, x, y[1]++, tab);
	}
	else
	{
		while (y[1] > y[0])
			store_pixel(wolf, x, y[1]--, tab);
	}
}

void	store_pixel(t_wolf *wolf, int x, int y, int *color)
{
	int	pos;

	pos = (wolf->width * y + x) * 4;
	wolf->data[pos++] = color[0];
	wolf->data[pos++] = color[1];
	wolf->data[pos] = color[2];
}
