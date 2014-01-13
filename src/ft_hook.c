/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 20:19:21 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/08 20:21:09 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <mlx.h>

int	ft_expose_hook(t_wolf *wolf)
{
	int res;

	res = mlx_put_image_to_window(wolf->mlx, wolf->window, wolf->image, 0, 0);
	return (res);
}
