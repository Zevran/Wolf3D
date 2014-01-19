/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:16:22 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/19 15:51:39 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <libft_converters.h>
#include <libft_printf.h>
#include <time.h>
#include <mlx.h>

void	ft_author(t_wolf *wolf)
{
	mlx_string_put(wolf->mlx, wolf->window, 10, 740, 0xFFFFFF, AUTHOR);
}

void	ft_fps_box(t_wolf *wolf)
{
	static long int	fps;
	static int		count;
	int				data[] = {60, 15, 10, 10};
	int				pos[] = {14, 22};
	int				pos2[] = {50, 22};

	count++;
	if (fps != time(NULL))
	{
		wolf->fps = count;
		count = 0;
		fps = time(NULL);
	}
	ft_draw_box(wolf, data, 0xFFFFFF);
	ft_draw_str(wolf, pos, 0x000000, "FPS :");
	ft_draw_str(wolf, pos2, 0x000000, ft_itoa(wolf->fps));
}

void	ft_draw_str(t_wolf *wolf, int data[2], int color, char *string)
{
	mlx_string_put(wolf->mlx, wolf->window, data[0], data[1], color, string);
}

void	ft_draw_box(t_wolf *wolf, int data[4], int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data[1])
	{
		j = 0;
		while (j <= data[0])
		{
			mlx_pixel_put(wolf->mlx, wolf->window, data[2] + j - 1, data[3] + i,
						color);
			j++;
		}
		i++;
	}
}

void	ft_draw_keys(t_wolf *wolf)
{
	int	left[] = {20, 20, wolf->width - 90, wolf->height - 40};
	int	right[] = {20, 20, wolf->width - 40, wolf->height - 40};
	int	up[] = {20, 20, wolf->width - 65, wolf->height - 65};
	int	down[] = {20, 20, wolf->width - 65, wolf->height - 40};

	ft_draw_box(wolf, left, 0xFFFFFF);
	ft_draw_box(wolf, right, 0xFFFFFF);
	ft_draw_box(wolf, up, 0xFFFFFF);
	ft_draw_box(wolf, down, 0xFFFFFF);
}

