/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:49:33 by greyrol           #+#    #+#             */
/*   Updated: 2014/11/09 14:49:34 by greyrol          ###   ########.fr       */
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
	static int				pos[2] = {14, 22};
	static int				pos2[2] = {50, 22};

	ft_draw_str(wolf, pos, 0x000000, "FPS :");
	ft_draw_str(wolf, pos2, 0x000000, ft_itoa(wolf->fps));
}

void	ft_fps_box(t_wolf *wolf)
{
	static long int	fps;
	static int		count;
	static int		data[] = {60, 15, 10, 10};

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
	static int	left[] = {20, 20, 1500 - 90, 750 - 40};
	static int	right[] = {20, 20, 1500 - 40, 750 - 40};
	static int	up[] = {20, 20, 1500 - 65, 750 - 65};
	static int	down[] = {20, 20, 1500 - 65, 750 - 40};

	ft_draw_square(wolf, left, 0xFFFFFF, 1);
	ft_draw_square(wolf, right, 0xFFFFFF, 1);
	ft_draw_square(wolf, up, 0xFFFFFF, 1);
	ft_draw_square(wolf, down, 0xFFFFFF, 1);
}

void	ft_draw_str_keys(t_wolf *wolf)
{
	static int	left[] = {1500 - 83, 750 - 25};
	static int	right[] = {1500 - 32, 750 - 25};
	static int	up[] = {1500 - 58, 750 - 50};
	static int	down[] = {1500 - 58, 750 - 25};

	ft_draw_str(wolf, left, 0x000000, "<");
	ft_draw_str(wolf, right, 0x000000, ">");
	ft_draw_str(wolf, up, 0x000000, "+");
	ft_draw_str(wolf, down, 0x000000, "-");
}
