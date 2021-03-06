/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:35:28 by greyrol           #+#    #+#             */
/*   Updated: 2014/11/09 14:35:30 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define AUTHOR "by greyrol"
# define W_LEFT 1
# define W_UP 2
# define W_RIGHT 4
# define W_BACK 8

typedef struct	s_wolf
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			width;
	int			height;
	int			**map;
	int			intern_map[2];
	int			step[2];
	int			collision;
	int			orientation;
	float		s_dist[2];
	float		d_dist[2];
	float		true_wall_dist;
	float		pos[2];
	float		dir[2];
	float		plane[2];
	float		camx;
	float		raypos[2];
	float		raydir[2];
	int			mov;
	int			up;
	int			fps;
}				t_wolf;

# define MAP_X wolf->intern_map[0]
# define MAP_Y wolf->intern_map[1]
# define STP_X wolf->step[0]
# define STP_Y wolf->step[1]
# define SDT_X wolf->s_dist[0]
# define SDT_Y wolf->s_dist[1]
# define DDT_X wolf->d_dist[0]
# define DDT_Y wolf->d_dist[1]
# define POS_X wolf->pos[0]
# define POS_Y wolf->pos[1]
# define DIR_X wolf->dir[0]
# define DIR_Y wolf->dir[1]
# define PLN_X wolf->plane[0]
# define PLN_Y wolf->plane[1]
# define RPS_X wolf->raypos[0]
# define RPS_Y wolf->raypos[1]
# define RDR_X wolf->raydir[0]
# define RDR_Y wolf->raydir[1]
# define W_WIDTH wolf->width
# define W_HEIGHT wolf->height

void			ft_get_map(t_wolf *wolf);
int				get_start_pos(int map[25][25], t_wolf *wolf);
void			ft_copy_map(int map[25][25], t_wolf *wolf);

void			init_wolf(t_wolf *wolf);

void			move_cam(float dirx, float diry, t_wolf *wolf);
void			turn_cam(float angle, float oldplanex, float olddirx,
						t_wolf *wolf);

int				ft_keys(t_wolf *wolf);
int				ft_expose_hook(t_wolf *wolf);
int				ft_get_key(int keycode, t_wolf *wolf);
int				ft_key_bind(int keycode, t_wolf *wolf);
void			ft_exit(t_wolf *wolf);

void			ft_init_dda(t_wolf *wolf);

void			ft_ray_pos(t_wolf *wolf, int x);
void			ft_get_dist(t_wolf *wolf);
void			ft_correct_feye(t_wolf *wolf);
void			ft_dig_diff_ana(t_wolf *wolf);
void			ft_get_wall_high(t_wolf *wolf, int x);
void			ft_render(t_wolf *wolf);

void			store_pixel(t_wolf *wolf, int x, int y, int color[3]);
void			ft_env_floor(t_wolf *wolf, int sy, int x);
void			ft_env_sky(t_wolf *wolf, int se, int x);
void			ft_env_line(t_wolf *wolf, int x, float *y, int color);

void			ft_author(t_wolf *wolf);
void			ft_fps_box(t_wolf *wolf);
void			ft_fps_str(t_wolf *wolf);
void			ft_draw_keys(t_wolf *wolf);
void			ft_draw_str_keys(t_wolf *wolf);

void			ft_draw_square(t_wolf *wolf, int data[4], int color, int mode);
void			ft_draw_str(t_wolf *wolf, int data[2], int color, char *string);
void			ft_pixel_put(t_wolf *wolf, int x, int y, int color);

void			init_pre_window(void);
int				main_pre_window(void);

#endif
