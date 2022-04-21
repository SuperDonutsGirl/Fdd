/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:34:43 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/16 12:34:45 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_common.h"

int	biggest(int x, int y)
{
	if (ft_abs(x) > ft_abs(y))
		return (ft_abs(x));
	return (ft_abs(y));
}

void	get_next_point(float *point_x, float *point_y, int type, t_map *map)
{
	if (type == 0)
	{
		*point_x = map->x + 1;
		*point_y = map->y;
	}
	else
	{
		*point_x = map->x;
		*point_y = map->y + 1;
	}
}

void	bresenham(float x, float y, int type, t_map *map)
{
	float	dist[2];
	float	next[2];
	float	z_point[2];
	int		max;

	get_next_point(&next[0], &next[1], type, map);
	z_point[0] = map->z[(int)y][(int)x];
	z_point[1] = map->z[(int)next[1]][(int)next[0]];
	animation(&x, &y, z_point[0], map);
	animation(&next[0], &next[1], z_point[1], map);
	dist[0] = next[0] - x;
	dist[1] = next[1] - y;
	max = biggest(dist[0], dist[1]);
	while ((int)(next[0] - x) > 0 || (int)(next[1] - y) > 0)
	{
		if (x >= 0 && x < WIDTH_WIN && y >= 0 && y < HEIGHT_WIN)
			ft_put_pixel(x, y, color(map, z_point[0]), map);
		x += dist[0] / max;
		y += dist[1] / max;
	}
}

void	ft_put_pixel(int x, int y, int color, t_map *map)
{
	int	pix;

	pix = (x * map->bits_per_pixel / 8) + (y * map->size_line);
	map->adr_img[pix] = color;
	map->adr_img[pix + 1] = color >> 8;
	map->adr_img[pix + 2] = color >> 16;
}

void	draw_line(t_map *map)
{
	map->y = 0;
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < map->width)
		{
			if (map->x < map->width - 1)
				bresenham(map->x, map->y, 0, map);
			if (map->y < map->height - 1)
				bresenham(map->x, map->y, 1, map);
			map->x++;
		}
		map->y++;
	}
}
