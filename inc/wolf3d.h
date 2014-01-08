/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:13:10 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/07 20:30:10 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include <mlx.h>
#include <math.h>

typedef struct	s_grid
{
	int	**grid;
}		t_grid;

typedef struct	s_map
{
	t_grid	*grid;
}				t_map;

#endif /* !WOLF3D_H */
