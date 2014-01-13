/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:13:10 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/09 22:42:30 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define KEY_ESCAPE 65301

/*
** Par convention les coordonnees d'un point sont de type (x, y)
** Ainsi sur un pointeur sur int, a[0] vaut a[x] & a[1] vaut a[y]
*/

typedef struct	s_bsh
{
	int	d;
	int	dx;
	int dy;
	int ai;
	int	bi;
	int	yi;
	int	xi;
	int	x;
	int	y;	
}				t_bsh;

typedef struct	s_map
{
	int		**grid;
	int		specs[5];
	int		start_pos[2];
}				t_map;

# define WIDTH specs[0]
# define HEIGHT specs[1]
# define WALL specs[2]
# define FLOOR specs[3]
# define SPAWN specs[4]
# define POS_X start_pos[0]
# define POS_Y start_pos[1]

typedef struct	s_env
{
	int		way[2];
	int		proj_plane[2];
	int		camera[2];
	int		ray_pos[2];
	int		ray_way[2];
	float	rot_speed;

}				t_env;

# define WAY_X wolf->env->way[0]
# define WAY_Y wolf->env->way[1]
# define CAM_X wolf->env->camera[0]
# define CAM_Y wolf->env->camera[1]
# define PLAN_X wolf->env->proj_plane[0]
# define PLAN_Y wolf->env->proj_plane[1]
# define RAY_P_X wolf->env->ray_pos[0]
# define RAY_P_Y wolf->env->ray_pos[1]
# define RAY_W_X wolf->env->ray_pos[0]
# define RAY_W_Y wolf->env->ray_pos[1]

typedef struct	s_wolf
{
	void	*mlx;
	void	*window;
	void	*image;
	int		width;
	int		height;
	int		move;
	int		index;
	t_map	*map;
	t_env	*env;
}				t_wolf;



t_wolf	*ft_wolf3d_init(t_wolf *wolf, char *argv[]);

t_map	*ft_init_map(t_map *map);
t_map	*ft_get_map_infos(t_map *map, char *infos_line);
t_map	*ft_get_map(t_map *map, char *map_file);

int		ft_key_press(t_wolf *wolf, int keycode);
int		ft_key_release(t_wolf *wolf, int keycode);

int		ft_get_frames(t_wolf *wolf);
int		ft_expose_hook(t_wolf *wolf);

void	ft_bsh_draw(t_wolf *wolf, int *x, int *y);

#endif /* !WOLF3D_H */
