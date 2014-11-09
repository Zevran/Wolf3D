/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:50:54 by greyrol           #+#    #+#             */
/*   Updated: 2014/11/09 14:50:55 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	store_pixel(t_wolf *wolf, int x, int y, int color[3])
{
	int	pos;

	pos = (y * wolf->width + x) * 4;
	wolf->data[pos++] = color[0];
	wolf->data[pos++] = color[1];
	wolf->data[pos] = color[2];
}

void	ft_env_floor(t_wolf *wolf, int sy, int x)
{
	int	y;
	int	color[3];

	color[0] = 0x09;
	color[1] = 0x37;
	color[2] = 0x5A;
	y = wolf->height - 1;
	while (y > sy)
		store_pixel(wolf, x, y--, color);
}

void	ft_env_sky(t_wolf *wolf, int se, int x)
{
	int		y;
	int		color[3];

	color[0] = 0xE9;
	color[1] = 0xBA;
	color[2] = 0x36;
	y = 0;
	while (y < se)
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
