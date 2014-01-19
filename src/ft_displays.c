/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:16:22 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/19 23:37:11 by greyrol          ###   ########.fr       */
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

void	ft_fps_str(t_wolf *wolf)
{
	int				pos[] = {14, 22};
	int				pos2[] = {50, 22};

	ft_draw_str(wolf, pos, 0x000000, "FPS :");
	ft_draw_str(wolf, pos2, 0x000000, ft_itoa(wolf->fps));
}

void	ft_fps_box(t_wolf *wolf)
{
	static long int	fps;
	static int		count;
	int				data[] = {60, 15, 10, 10};

	count++;
	if (fps != time(NULL))
	{
		wolf->fps = count;
		count = 0;
		fps = time(NULL);
	}
	ft_draw_square(wolf, data, 0xFFFFFF, 1);
}

void	ft_draw_keys(t_wolf *wolf)
{
	int	left[] = {20, 20, wolf->width - 90, wolf->height - 40};
	int	right[] = {20, 20, wolf->width - 40, wolf->height - 40};
	int	up[] = {20, 20, wolf->width - 65, wolf->height - 65};
	int	down[] = {20, 20, wolf->width - 65, wolf->height - 40};

	ft_draw_square(wolf, left, 0xFFFFFF, 1);
	ft_draw_square(wolf, right, 0xFFFFFF, 1);
	ft_draw_square(wolf, up, 0xFFFFFF, 1);
	ft_draw_square(wolf, down, 0xFFFFFF, 1);
}

void	ft_draw_str_keys(t_wolf *wolf)
{
	int	left[] = {wolf->width - 40, wolf->height - 40};
	int	right[] = {wolf->width - 90, wolf->height - 40};
	int	up[] = {wolf->width - 65, wolf->height - 65};
	int	down[] = {wolf->width - 65, wolf->height - 40};

	ft_draw_str(wolf, left, 0x000000, "<");
	ft_draw_str(wolf, right, 0x000000, ">");
	ft_draw_str(wolf, up, 0x000000, "^");
	ft_draw_str(wolf, down, 0x000000, "-");
}

