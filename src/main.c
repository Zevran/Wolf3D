/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:37:42 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/18 18:04:40 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <libft_printf.h>
#include <mlx.h>

void	init_wolf(t_wolf *wolf)
{
	wolf->width = 1200;
	wolf->height = 700;
	DIR_X = -1;
	DIR_Y = 0;
	wolf->up = 0;
	PLN_X = 0;
	PLN_Y = 0.66;
	wolf->mov = 0;
	wolf->mlx = mlx_init();
	wolf->window = mlx_new_window(wolf->mlx, wolf->width, wolf->height,
														  "WOLF3D");
	wolf->image = mlx_new_image(wolf->mlx, wolf->width, wolf->height);
	wolf->data = mlx_get_data_addr(wolf->image, &wolf->bpp, &wolf->size_l,
															&wolf->endian);
}

int		main(void)
{
	t_wolf		*wolf;

	wolf = (t_wolf *) malloc(sizeof(t_wolf));
	init_wolf(wolf);
	ft_get_map(wolf);
	mlx_hook(wolf->window, 1, 1, &ft_key_hook, wolf);
	ft_render(wolf);
	mlx_do_key_autorepeatoff(wolf->mlx);
	mlx_hook(wolf->window, 2, 2, ft_key_hook, wolf);
	mlx_hook(wolf->window, 3, 3, ft_key_release, wolf);
	mlx_expose_hook(wolf->window, ft_expose_hook, wolf);
	mlx_loop_hook(wolf->mlx, ft_keys, wolf);
	mlx_loop(wolf->mlx);
	return (0);
}
