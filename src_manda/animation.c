/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:22:27 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/16 11:22:29 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	color(t_map *map, int z)
{
	map++;
	z++;
	return (WHITE);
}

void	intit_zoom(t_map *map)
{
	if (map->width <= 27)
	{
		map->zoom = 10;
		if (map->width == 21 && map->height == 20)
			map->zoom = 8;
	}
	else if (map->width <= 101)
		map->zoom = 8;
	else if (map->width == 200)
		map->zoom = 3.5;
	else
		map->zoom = 2;
	map->center[0] = 0;
	map->center[1] = 0;
}

void	init_center(t_map *map)
{
	if (map->zoom == 10)
	{
		map->center[0] = (WIDTH_WIN / 2) - (map->width / 2);
		map->center[1] = (HEIGHT_WIN / 2) - (map->height * 2);
	}
	if (map->zoom == 8)
	{
		map->center[0] = (WIDTH_WIN / 2) - (map->width / 2);
		if (map->width >= 48)
			map->center[1] = (HEIGHT_WIN / 2) - map->height * 2;
		else
			map->center[1] = 0;
	}
	if (map->zoom == 2)
	{
		map->center[0] = (WIDTH_WIN / 2) ;
		map->center[1] = 0;
	}
	if (map->zoom == 3.5)
	{
		map->center[0] = (WIDTH_WIN / 2);
		map->center[1] = (HEIGHT_WIN / 2) - (map->height * 2);
	}
}

void	animation(float *x, float *y, int z, t_map *map)
{
	intit_zoom(map);
	init_center(map);
	map->div_rad = 3;
	*x = (*x - *y) * cos(M_PI / map->div_rad);
	*y = (*x + *y) * sin(M_PI / map->div_rad) - z * cos(M_PI / map->div_rad);
	*x *= map->zoom;
	*y *= map->zoom;
	*x += map->center[0];
	*y += map->center[1];
	//*x += (WIDTH_WIN / 2) - (map->width / 2);
	//*y += (HEIGHT_WIN / 2) - (map->height / 2);
}
