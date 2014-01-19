/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 17:45:23 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/19 19:19:55 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>

/*void	ft_draw_triangle(t_wolf *wolf, int data[6], int color)
{
	int	dst_far;
	int	dst_upper;
	int	dst_low;
	int	xf;
	int	xt;

	dst_far = (data[4] - data[0])
}*/

/*
** data[0] : square's width
** data[1] : square's height
** data[2] : square's start in x on window
** data[3] : square's start in y on window
** mode(1) : put pixel on image / mode(0) : put pixel on window
*/

void	ft_draw_square(t_wolf *wolf, int data[4], int color, int mode)
{
	int	j;
	int	i;

	i = 0;
	while (i <= data[1])
	{
		j = 0;
		while (j <= data[0])
		{
			if (mode)
				ft_pixel_put(wolf, data[2] + j - 1, data[3] + i, color);
			else
				mlx_pixel_put(wolf->mlx, wolf->window, data[2] + j - 1,
							data[3] + i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_str(t_wolf *wolf, int data[2], int color, char *string)
{
	mlx_string_put(wolf->mlx, wolf->window, data[0], data[1], color, string);
}

void	ft_pixel_put(t_wolf *wolf, int x, int y, int color)
{
	unsigned int	c;

	c = mlx_get_color_value(wolf->mlx, color);
	wolf->data[y * wolf->size_l + (wolf->bpp / 8) * x] = c & 0xFF;
	wolf->data[1 + y * wolf->size_l + (wolf->bpp / 8) * x] = c >> 8 & 0xFF;
	wolf->data[2 + y * wolf->size_l + (wolf->bpp / 8) * x] = c >> 16 & 0xFF;
}
