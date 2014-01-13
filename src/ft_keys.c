/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 19:39:34 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/08 20:21:48 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>
#include <mlx.h>

int	ft_key_press(t_wolf *wolf, int keycode)
{
	if (keycode == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (keycode >= 65361 && keycode <= 65364)
		wolf->move += keycode % 10;
	return (0);
}

int	ft_key_release(t_wolf *wolf, int keycode)
{
	if (keycode == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	return (0);
	if (keycode >= 65361 && keycode <= 65364)
		wolf->move -= keycode % 10;
	wolf->index = mlx_put_image_to_window(wolf->mlx,
										  wolf->window,
										  wolf->image, 0, 0);
	return (0);
}

