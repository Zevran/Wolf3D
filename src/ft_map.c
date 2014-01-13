/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greyrol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 20:07:23 by greyrol           #+#    #+#             */
/*   Updated: 2014/01/08 22:06:36 by greyrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <libft_string.h>
#include <libft_converters.h>
#include <libft_printf.h>
#include <fcntl.h>
#include <stdio.h>

t_map	*ft_init_map(t_map *map)
{
	map = (t_map *) malloc(sizeof(t_map));
	return (map);
}

t_map	*ft_get_map_infos(t_map *map, char *infos_line)
{
	int		i;
	char	**specs;

	i = 0;
	specs = ft_strtok(ft_strchr(infos_line, '=') + 1, ':');
	if (specs && *specs)
	{
		while (*specs)
		{
			map->specs[i] = ft_atol(*specs);
			i++;
			specs++;
		}
	}
	return (map);
}

t_map	*ft_line2int(t_map *map, int *y, char *line)
{
	int	x;

	x = 0;
	map->grid[*y] = (int *) malloc(sizeof(int) * map->WIDTH);
	while (*line && map->grid[*y])
	{
		if (ft_isdigit(*line))
		{
			map->grid[*y][x] = ft_atol(line);
			x++;
		}
		line++;
	}
	return (map);
}

t_map	*ft_get_map(t_map *map, char *map_file)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	map = ft_init_map(map);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		perror("wold3d: error");
	if (ft_readline(fd, &line) > 0)
		map = ft_get_map_infos(map, line);
	else
		ft_error("wolf3d: error: Map's infos are corrupted\n");
	map->grid = (int **) malloc(sizeof(int) * (map->WIDTH * map->HEIGHT));
	while (ft_readline(fd, &line) > 0 && map->grid)
	{
		map = ft_line2int(map, &y, line);
		y++;
	}
	return (map);
}
