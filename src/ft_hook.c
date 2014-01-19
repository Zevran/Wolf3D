/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:00:44 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/19 23:38:52 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>
#include <stdlib.h>
#include <math.h>

static void	ft_func_keys(t_wolf *wolf, int keys[4][4], int color, int mode)
{
	if (wolf->mov & W_UP)
	{
		move(wolf->dir[0], wolf->dir[1], wolf);
		ft_draw_square(wolf, keys[2], color, mode);
	}
	if (wolf->mov & W_BACK)
	{
		move(-wolf->dir[0], -wolf->dir[1], wolf);
		ft_draw_square(wolf, keys[3], color, mode);
	}
	if (wolf->mov & W_RIGHT && !(wolf->mov & W_LEFT))
	{
		turn(-0.025, wolf->plane[0], wolf->dir[0], wolf);
		ft_draw_square(wolf, keys[1], color, mode);
	}
	if (wolf->mov & W_LEFT && !(wolf->mov & W_RIGHT))
	{
		turn(0.025, wolf->plane[0], wolf->dir[0], wolf);
		ft_draw_square(wolf, keys[0], 0x999999, mode);
	}
}

int			ft_keys(t_wolf *wolf)
{
	int	keys[4][4] =
	{
		{20, 20, wolf->width - 90, wolf->height - 40},
		{20, 20, wolf->width - 40, wolf->height - 40},
		{20, 20, wolf->width - 65, wolf->height - 65},
		{20, 20, wolf->width - 65, wolf->height - 40}
	};
	ft_func_keys(wolf, keys, 0x999999, 0);
	ft_render(wolf);
	mlx_put_image_to_window(wolf->mlx, wolf->window, wolf->image, 0, 0);
	ft_author(wolf);
	ft_fps_str(wolf);
	ft_draw_str_keys(wolf);
	return (0);
}

static void	ft_func_bind(t_wolf *wolf, int keycode, int keys[4][4], int color)
{
	if (keycode == 65363)
	{
		wolf->mov = wolf->mov ^ W_RIGHT;
		ft_draw_square(wolf, keys[1], color, 0);
	}
	if (keycode == 65364)
	{
		wolf->mov = wolf->mov ^ W_BACK;
		ft_draw_square(wolf, keys[3], color, 0);
	}
	if (keycode == 65361)
	{
		wolf->mov = wolf->mov ^ W_LEFT;
		ft_draw_square(wolf, keys[0], color, 0);
	}
	if (keycode == 65362)
	{
		wolf->mov = wolf->mov ^ W_UP;
		ft_draw_square(wolf, keys[2], color, 0);
	}
	else
		wolf->mov = wolf->mov;
}

int			ft_key_bind(int keycode, t_wolf *wolf)
{
	int	keys[4][4] =
	{
		{20, 20, wolf->width - 90, wolf->height - 40},
		{20, 20, wolf->width - 40, wolf->height - 40},
		{20, 20, wolf->width - 65, wolf->height - 65},
		{20, 20, wolf->width - 65, wolf->height - 40}
	};

	if (keycode == 65307)
		exit(0);
	ft_func_bind(wolf, keycode, keys, 0x999999);
	return (0);
}

int			ft_expose_hook(t_wolf *wolf)
{
	int		i;

	i = mlx_put_image_to_window(wolf->mlx, wolf->window, wolf->image, 0, 0);
	return (i);
}
