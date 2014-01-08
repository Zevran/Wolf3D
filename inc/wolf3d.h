/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:13:10 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/08 16:13:32 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

typedef struct	s_map
{
	int		**grid;
	int		specs[5];
}				t_map;

typedef struct	s_wolf
{
	void	*mlx;
	void	*window;
	void	*image;
	int		width;
	int		height;
	t_map	*map;
}				t_wolf;

t_map	*ft_init_map(t_map *map);
t_map	*ft_get_map_infos(t_map *map, char *infos_line);
t_map	*ft_get_map(t_map *map, char *map_file);

#endif /* !WOLF3D_H */
