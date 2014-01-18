/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:00:44 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/18 18:09:38 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>
#include <stdlib.h>
#include <math.h>

int		ft_keys(t_wolf *wolf)
{
	if (wolf->mov & W_UP)
		move(wolf->dir[0], wolf->dir[1], wolf);
	if (wolf->mov & W_BACK)
		move(-wolf->dir[0], wolf->dir[1], wolf);
	if (wolf->mov & W_RIGHT && !(wolf->mov & W_LEFT))
		turn(-0.025, wolf->plane[0], wolf->dir[0], wolf);
	if (wolf->mov & W_LEFT && !(wolf->mov & W_RIGHT))
		turn(0.025, wolf->plane[0], wolf->dir[0], wolf);
	ft_render(wolf);
	mlx_put_image_to_window(wolf->mlx, wolf->window, wolf->image, 0, 0);
	mlx_string_put(wolf->mlx, wolf->window, 10, 15, 0xFFFFFF, "by greyrol");
	return (0);
}

int		ft_key_hook(int keycode, t_wolf *wolf)
{
	if (keycode == 65307)
		exit(0);
	wolf->mov = (keycode == 65363 ? wolf->mov ^ W_RIGHT : wolf->mov);
	wolf->mov = (keycode == 65364 ? wolf->mov ^ W_BACK : wolf->mov);
	wolf->mov = (keycode == 65361 ? wolf->mov ^ W_LEFT : wolf->mov);
	wolf->mov = (keycode == 65362 ? wolf->mov ^ W_UP : wolf->mov);
	return (0);
}

int		ft_key_release(int keycode, t_wolf *wolf)
{
	wolf->mov = (keycode == 65363 ? wolf->mov ^ W_RIGHT : wolf->mov);
	wolf->mov = (keycode == 65364 ? wolf->mov ^ W_BACK : wolf->mov);
	wolf->mov = (keycode == 65361 ? wolf->mov ^ W_LEFT : wolf->mov);
	wolf->mov = (keycode == 65362 ? wolf->mov ^ W_UP : wolf->mov);
	return (0);
}

int		ft_expose_hook(t_wolf *wolf)
{
	int		i;

	i = mlx_put_image_to_window(wolf->mlx, wolf->window, wolf->image, 0, 0);
	return (i);
}
